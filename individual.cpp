#include "individual.hpp"

individual::individual(unsigned short int dna_dimensions) : fitness(0.f) {
    my_dna = new dna(dna_dimensions);
}

individual::~individual() {
    delete my_dna;
}
