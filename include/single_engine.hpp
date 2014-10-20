#pragma once

#include "engine.hpp"
#include "dna.hpp"
#include "rand.hpp"
#include "crossover.hpp"
#include "mutation.hpp"
#include "selection_type.hpp"
#include <cmath>

typedef float(*FitnessCallbackPtr)(void*, const dna &);

class single_engine : public engine {
    std::vector<dna>  dna_buffer;
    std::vector<bool> dna_checked;
    std::vector<float>acc_fitness;

    //float (*fitness_callback)(const dna &);
    FitnessCallbackPtr fitness_callback;
    void *fitness_inst_callback;

    void configEngine      (void);
    void makeSelection    (unsigned short int selection_start_point);
    void makeElitism      (unsigned short int n_elitists);
    void makeCrossover    (unsigned short int n_cross);
    void makeMutation     (unsigned short int n_mutat);
    void updateIndividuals(void);
    void manageGoals      (void);

    public:
        //void setFitnessCallback(float(*callback)(const dna &));
        void setFitnessCallback(FitnessCallbackPtr function_ptr, void *instance_ptr);

        void configEngine(population &the_population,simulation &the_simulation);
        void stepEngine(void);
};
