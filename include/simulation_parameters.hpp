#pragma once

#include "goals.hpp"
#include "crossover_type.hpp"

struct simulation_parameters {
    float cross_prob,  mutat_prob,  elitism_ratio;
    float cross_scale, mutat_scale, elitism_scale;
    float diverg_goal;
    unsigned short int gen_goal;
    goals goal;
    crossover_type cross_type;
};
