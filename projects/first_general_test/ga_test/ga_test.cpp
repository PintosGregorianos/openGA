/**----------------------- Hill Climbing with openGA-------------------------------

Generate a one dimension random space and search the global maximum using openGA.

Created by Diego Pinto and Gregory Gusberti @ 2014/2
---------------------------------------------------------------------------------**/

#include "openGA.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

///Espaço aleatorio de uma dimensao
//------------------------------------------------------
// salva aquivo do matlab pra plotat
// #define SPACE_FILE
#ifdef SPACE_FILE
    const std::string space_file_name = "rand_space.dat";
#endif

const std::size_t space_size = 4096;
float space[space_size];
float global_maximum;

void generate_space(void);
//------------------------------------------------------

float evaluateFitness(const dna &the_dna);

int main() {
    seed_from_time();

    std::cout << std::endl;

    ///gera espaco aleatorio
    generate_space();


    ///populacao
    //------------------------------------------------
    population my_pop;

    my_pop.setPopulationSize      (25);
    my_pop.setDNADimension        (1);
    //------------------------------------------------


    ///simulacao
    //------------------------------------------------
    simulation my_sim;

    my_sim.setCrossoverProbability(0.65f);
    my_sim.setMutationProbability (0.08f);
    my_sim.setElitismRatio        (0.1f);
    my_sim.setCrossoverType       (crossover_type::onePoint);

    my_sim.setCrossoverScaleFactor(1.f);
    my_sim.setMutationScaleFactor (1.f);
    my_sim.setElitismScaleFactor  (1.f);

    my_sim.setGoalGeneration      (25);
    my_sim.setGoals               (goals::generation);
    // -----------------------------------------------


    ///motor
    //------------------------------------------------
    single_engine my_eng;

    my_eng.setFitnessCallback     (evaluateFitness);
    my_eng.startEngine            (my_pop,my_sim);

    while(my_sim.getAchievedGoals() != goals::generation) {
        my_eng.stepEngine();
    }

    ///mostra resultado
    std::cout << "\nRESULTADOS\n";
    std::cout << "\tMaximo global por bruta forca: " << global_maximum << std::endl;
    std::cout << "\tGeracao final: " << my_pop.getGeneration() << std::endl;
    my_pop.calcDivergence();
    std::cout << "\tDivergencia: " << my_pop.getDivergence(0) << std::endl;
    for (size_t i = 0; i < my_pop.getPopulationSize(); i++)
        std::cout << "\t\tIndividuo " << i << ": " << evaluateFitness(my_pop.acessIndividualDNA(i)) << std::endl;


    return 0;
}

void generate_space(void) {
    const float max_derivative   = 2.f;
    const float max_2derivative  = 0.5;
    float derivative = 0;
    float g_maximum = -999999999.f,g_minimum = 999999999.f;
    space[0] = 0.f;

    for (size_t i = 1; i < space_size; i++) {
        derivative += (real_rand()*2.f - 1.f)*max_2derivative;
        derivative = std::min(max_derivative,std::max(-max_derivative,derivative));
        space[i] = space[i-1] + derivative;
        if (space[i] > g_maximum)
            g_maximum = space[i];
        if (space[i] < g_minimum)
            g_minimum = space[i];
    }
    #ifdef SPACE_FILE
        std::ofstream file(space_file_name.c_str());
        if (!file.is_open())
            return;
    #endif
    for (size_t i = 0; i < space_size; i++) {
        space[i] -= g_minimum;
        #ifdef SPACE_FILE
            file << space[i] << std::endl;
        #endif
    }
    #ifdef SPACE_FILE
        file.close();
    #endif
    global_maximum = g_maximum - g_minimum;
}

float evaluateFitness(const dna &the_dna) {
    return space[(std::size_t)round(the_dna.getChromossomeAsReal(0)*(space_size-1))];
}

