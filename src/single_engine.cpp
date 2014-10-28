#include "single_engine.hpp"

void single_engine::configEngine(void) {
    dna_buffer.resize (p_population->params.population_size);
    for (size_t i = 0; i < p_population->params.population_size; i++) dna_buffer[i].create(p_population->params.dna_dimensions);
    dna_checked.resize(p_population->params.population_size);
    acc_fitness.resize(p_population->params.population_size+1);
}

void single_engine::stepEngine(void) {
    #ifdef DEBUG_MODE
        std::cout << "\nWORK FOR GENERATION " << p_population->getGeneration() << std::endl;
    #endif // DEBUG_MODE

    for (auto &&x : dna_checked) x = false;

    unsigned short int n_elitists, n_cross, n_mutat;
    n_elitists = round((float)p_population->params.population_size*p_simulation->params.elitism_ratio);
    n_cross    = round((float)p_population->params.population_size*p_simulation->params.cross_prob);
    n_mutat    = round((float)p_population->params.population_size*p_simulation->params.mutat_prob);

    // C�lcula fitness pra cada indiv�duo
    if (fitness_callback != nullptr) {
        for (size_t i = 0; i < p_population->params.population_size; i++) {
            p_population->individuals[i]->fitness = fitness_callback(*p_population->individuals[i]->my_dna);
        }
    }
    else {
        PRINT_ERROR("Engine fitness callback not defined!");
    }

    // ordena individuos em ordem crescente de fitness
    sort(p_population->individuals.begin(), p_population->individuals.end(), individual_comp());

    ///SORT DEBUG ----------------------------------------------------------------------
    #ifdef DEBUG_MODE
        std::cout << "\nSorted fitness" << std::endl;
        for (size_t i = 0; i < p_population->params.population_size; i++) {
            std::cout << "\tIndividual " << i << ": " << p_population->individuals[i]->fitness << std::endl;
        }
        std::cout << std::endl;
    #endif
    ///---------------------------------------------------------------------------------

    // sele��o natural
    makeElitism  (n_elitists);
    makeSelection(n_elitists);

    // crossover
    makeCrossover(n_cross);

    // muta��o
    makeMutation (n_mutat, n_elitists);

    // atualiza indiv�duos com novos DNAs
    updateIndividuals();

    // evolui populacao
    p_population->increase_gen();

    // verifica goals. se necessario calcula divergenceia
    manageGoals();

    // atualiza par�metros conforme fatores de escala
    p_simulation->params.cross_prob    *= p_simulation->params.cross_scale;
    p_simulation->params.mutat_prob    *= p_simulation->params.mutat_scale;
    p_simulation->params.elitism_ratio *= p_simulation->params.elitism_scale;
}

// cuidado, m�todo er�tico e sensual.
// para o correto crossover n�o use camisinha
void single_engine::makeCrossover(unsigned short int n_cross) {
    if (!n_cross) return;
    #ifdef DEBUG_MODE
        std::cout << std::endl << "Crossovers:" << std::endl;
    #endif // DEBUG_MODE

    auto &individuals = p_population->individuals;

    crossover cross;

    size_t n = 0;
    size_t n2 = 0;
    size_t id1,id2;
    switch(p_simulation->params.cross_type) {
        case(crossover_type::onePoint):
            while(n++ < n_cross) {
                id1 = uint_rand()%p_population->params.population_size;
                id2 = uint_rand()%p_population->params.population_size;
                cross.typeA(dna_buffer[id1],dna_buffer[id2],dna_buffer[n2],dna_buffer[n2+1]);
                n2+=2;
                #ifdef DEBUG_MODE
                    std::cout << "\tIndividual " << id1 << " <-> Individual " << id2 << std::endl;
                #endif // DEBUG_MODE
            }
            break;
        case(crossover_type::twoPoint):
            while(n++ < n_cross) {
                id1 = uint_rand()%p_population->params.population_size;
                id2 = uint_rand()%p_population->params.population_size;
                cross.typeB(dna_buffer[id1],dna_buffer[id2],dna_buffer[n2],dna_buffer[n2+1]);
                n2+=2;
                #ifdef DEBUG_MODE
                    std::cout << "\tIndividual " << id1 << " <-> Individual " << id2 << std::endl;
                #endif // DEBUG_MODE
            }
            break;
        case(crossover_type::cutSplice):
            while(n++ < n_cross) {
                id1 = uint_rand()%p_population->params.population_size;
                id2 = uint_rand()%p_population->params.population_size;
                cross.typeC(dna_buffer[id1],dna_buffer[id2],dna_buffer[n2],dna_buffer[n2+1]);
                n2+=2;
                #ifdef DEBUG_MODE
                    std::cout << "\tIndividual " << id1 << " <-> Individual " << id2 << std::endl;
                #endif // DEBUG_MODE
            }
            break;
    }
    #ifdef DEBUG_MODE
        std::cout << std::endl;
    #endif // DEBUG_MODE
}

void single_engine::makeSelection(unsigned short int n_elitists) {
    acc_fitness[0] = 0.f;

    auto &individuals = p_population->individuals;

    // aten��o! nmax vai permitir a sele��o de indiv�duos que ser�o sobre escritos pelo
    // crossover. Definir um ponto final para a sele��o.
    unsigned short int nmax = individuals.size()-n_elitists-1;

    /// talvez dividir em outro m�todo ou classe "selection" ?
    switch(p_simulation->params.select_type) {
        case(selection_types::roulette::linearFitness):
            for (size_t i = 0; i <= nmax; i++) acc_fitness[i+1] = acc_fitness[i] + individuals[i]->fitness;
            break;
        case(selection_types::roulette::expFitness):
            for (size_t i = 0; i <= nmax; i++) acc_fitness[i+1] = acc_fitness[i] + individuals[i]->fitness*individuals[i]->fitness;
            break;
        case(selection_types::roulette::linearScore):
            for (size_t i = 0; i <= nmax; i++) acc_fitness[i+1] = acc_fitness[i] + (float)(i + 1);
            break;
        case(selection_types::roulette::expScore):
            for (size_t i = 0; i <= nmax; i++) acc_fitness[i+1] = acc_fitness[i] + (float)((i + 1)*(i + 1));
            break;
        default:
            #ifdef DEBUG_MODE
                PRINT_ERROR("Single-engine: Don't know the selected selection type");
            #endif // DEBUG_MODE
            break;
    }


    size_t n = 0;
    float choice, fitness_sum;
    size_t selector;
    fitness_sum = acc_fitness[nmax+1];
    #ifdef DEBUG_MODE
        std::cout << "\nIndividuals fitness from natural selection: \n";
    #endif // DEBUG_MODE
    while (n <= nmax) {
        choice   = real_rand()*fitness_sum;
        selector = nmax+1;
        while(choice <= acc_fitness[selector]) selector--;
        #ifdef DEBUG_MODE
            std::cout << "\t Individual " << n << ": " << individuals[selector]->fitness << std::endl;
        #endif // DEBUG_MODE
        dna_buffer[n++] = *individuals[selector]->my_dna;
    }
    #ifdef DEBUG_MODE
        std::cout << std::endl;
    #endif // DEBUG_MODE
}

// Otimizar contadores n e n2 fiz do jeito idiota
void single_engine::makeElitism(unsigned short int n_elitists) {
    if (!n_elitists) return;
    size_t n  = 0;
    size_t n2 = p_population->params.population_size-1;
    #ifdef DEBUG_MODE
        std::cout << "Selected elitists's fitness: " << std::endl;
    #endif // DEBUG_MODE
    while(n++ < n_elitists) {
        dna_buffer[n2] = *p_population->individuals[n2]->my_dna;
        #ifdef DEBUG_MODE
            std::cout << "\tIndividual " << n2 << ": " << p_population->individuals[n2]->fitness << std::endl;
        #endif // DEBUG_MODE
        n2--;
    }
    #ifdef DEBUG_MODE
        std::cout << std::endl;
    #endif // DEBUG_MODE
}

// Apenas implementado o tipo A por enquanto
void single_engine::makeMutation(unsigned short int n_mutat, unsigned short int elite_reject_point) {
    #ifdef DEBUG_MODE
        std::cout << std::endl;
    #endif // DEBUG_MODE
    size_t n = 0;
    size_t selected;
    while(n++ < n_mutat) {
        do {
            selected = uint_rand()%p_population->params.population_size;
        }
        while(dna_checked[selected] || selected>=p_population->params.population_size-elite_reject_point);
        dna_checked[selected] = true;
        mutation::typeA(dna_buffer[selected]);
        #ifdef DEBUG_MODE
            std::cout << "Mutate individual " << selected << std::endl;
        #endif // DEBUG_MODE
    }
    #ifdef DEBUG_MODE
        std::cout << std::endl;
    #endif // DEBUG_MODE
}

// Vai ser assim pra sempre? ou usar double buffering?
// - girando a roleta do silvio santos
// - caiu no double buffering
// Quem vai fazer?
// - girando a roleta do silvio santos
// FATAL ERROR
// �, vai ser o pinto
void single_engine::updateIndividuals(void) {
    for (size_t i = 0; i < p_population->params.population_size; i++) {
        *p_population->individuals[i]->my_dna = dna_buffer[i];
    }
}

void single_engine::manageGoals(void) {
    ///GOAL POR DIVERGENCIA
    // metrica talvez nao muito boa, seta o goal quando a divergencia de cada dimensao e menor que a do goal
    if (p_simulation->params.goal & goals::divergence) {
        p_population->calcDivergence();
        const float *diverg = p_population->getDivergences();
        bool yep = true;
        for (size_t i = 0; i < p_population->params.dna_dimensions; i++) {
            if (diverg[i] > p_simulation->params.diverg_goal) {
                yep = false;
                break;
            }
        }
        if (yep) p_simulation->achieved_goals |= goals::divergence;
    }

    /// GOAL POR GERA��O
    if (p_simulation->params.goal & goals::generation) {
        if (p_population->gen_counter >= p_simulation->params.gen_goal)
            p_simulation->achieved_goals |= goals::generation;
    }
}

//void single_engine::setFitnessCallback(float(*callback)(const dna &)) {
void single_engine::setFitnessCallback(FitnessCallbackPtr callback){
    fitness_callback = callback;
    //fitness_inst_callback = instance_ptr;
}

void single_engine::configEngine(population &the_population,simulation &the_simulation) {
    bindEngine(&the_population,&the_simulation);

    configEngine();

    p_population->populate();
}
