#include "population.hpp"

const dna& population::acessIndividualDNA(unsigned short int individual_id) const {
    return *individuals[individual_id]->my_dna;
}

dna population::getIndividualDNA(unsigned short int individual_id) const {
    return *individuals[individual_id]->my_dna;
}

population::~population() {
    for (std::size_t i = 0; i < params.population_size; i++) {
        delete individuals[i];
    }
}

void population::populate(void) {
    individuals.resize(params.population_size);

    diverg = new float[params.dna_dimensions];

    for (std::size_t i = 0; i < params.population_size; i++) {
        individuals[i]   = new individual(params.dna_dimensions);
    }

    gen_counter = 1;
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
    for (i = 0; i < params.dna_dimensions; i++) diverg[k] = sqrt(diverg[k]/((params.population_size*(params.population_size-1))));
}

float population::getDivergence(unsigned short int chrom_id) const {
    return diverg[chrom_id];
}

const float *population::getDivergences(void) const {
    return diverg;
}
