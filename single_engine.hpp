#pragma once

#include "engine.hpp"
#include "dna.hpp"
#include "rand.hpp"
#include "crossover.hpp"
#include "mutation.hpp"
#include "goals.hpp"
#include <cmath>

class single_engine : public engine {
    std::vector<dna>  dna_buffer;
    std::vector<bool> dna_checked;
    std::vector<float>acc_fitness;

    void startEngine(void);
    void stepEngine(void);
    void makeSelection(unsigned short int selection_start_point);
    void makeElitism(unsigned short int n_elitists);
    void makeCrossover(unsigned short int n_cross);
    void makeMutation(unsigned short int n_mutat);
    void updateIndividuals(void);
    void manageGoals(void);

};
