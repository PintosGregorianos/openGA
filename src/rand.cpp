#include "rand.hpp"

std::default_random_engine rand_gen;

std::uniform_real_distribution<float>       real_rand_dist(0.f,1.f);
std::uniform_int_distribution<unsigned int> uint_rand_dist(0,~0);
