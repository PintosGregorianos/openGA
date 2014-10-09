#include "individual.hpp"

individual::individual() : fitness(0.f) {
    my_dna = new dna;
}

individual::~individual() {
    if (my_dna)
        delete my_dna;
}
