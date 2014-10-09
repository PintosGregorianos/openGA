#include "population.hpp"

const dna& population::acessIndividualDNA(unsigned short int individual_id) const {
    return *individuals[individual_id]->my_dna;
}

dna population::getIndividualDNA(unsigned short int individual_id) const {
    return *individuals[individual_id]->my_dna;
}

population::~population() {
    deleteIndividuals();
    if (diverg != nullptr)
        delete diverg;
}

population::population() {
    gen_counter = 1;
}

void population::populate(void) {
    deleteIndividuals();
    individuals.resize(params.population_size);
    for (size_t i = 0; i < params.population_size; i++) {
        individuals[i] = new individual;
        individuals[i]->my_dna->create(params.dna_dimensions);
    }

    if (diverg != nullptr)
        delete diverg;

    diverg = new float[params.dna_dimensions];
}

// calcula distancia RMS dos cromossomos
// calculo separado para cada dimensao do DNA
void population::calcDivergence(void) {
    std::size_t i,j,k;
    float temp;
    for (i = 0; i < params.dna_dimensions; i++) diverg[i] = 0.f;
    for (i = 0; i < params.population_size; i++) {
        for (j = i+1; j < params.population_size; j++) {
            for (k = 0; k < params.dna_dimensions; k++) {
                temp = (float)individuals[i]->my_dna->chromossomes[k] - (float)individuals[j]->my_dna->chromossomes[k];
                diverg[k] += temp*temp;
            }
        }
    }
    for (i = 0; i < params.dna_dimensions; i++) diverg[i] = sqrt(diverg[i]/(float)((params.population_size*(params.population_size-1))));
}

void population::deleteIndividuals(void) const {
    if (individuals.empty()) return;
    for (std::size_t i = 0; i < params.population_size; i++)
        delete individuals[i];
}

float population::getDivergence(unsigned short int chrom_id) const {
    return diverg[chrom_id];
}

const float *population::getDivergences(void) const {
    return diverg;
}

void population::increase_gen(void) {
    gen_counter++;
}

void population::setPopulationSize(unsigned short int size) {
    if (size > 0)
        params.population_size = size;
    else {
        params.population_size = 1;
        PRINT_ERROR("Zero or negative population size. Seted to 1 individual.");
    }
}
void population::setDNADimension  (unsigned short int dimension) {
    if (dimension > 0)
        params.dna_dimensions = dimension;
    else {
        params.dna_dimensions = 1;
        PRINT_ERROR("Zero or negative DNA dimension. Seted to 1 dimension.");
    }
}

unsigned short int population::getPopulationSize(void) const {
    return params.population_size;
}

unsigned short int population::getDNADimension  (void) const {
    return params.dna_dimensions;
}

unsigned short int population::getGeneration(void) const {
    return gen_counter;
}
