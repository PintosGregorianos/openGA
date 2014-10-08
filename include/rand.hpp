#pragma once

#include <random>
#include <chrono>

extern std::default_random_engine rand_gen;

extern std::uniform_real_distribution<float>       real_rand_dist;
extern std::uniform_int_distribution<unsigned int> uint_rand_dist;

inline float real_rand(void) {
	return real_rand_dist(rand_gen);
}

inline unsigned int uint_rand(void) {
	return uint_rand_dist(rand_gen);
}

inline void seed_from_time(void) {
    rand_gen.seed(std::chrono::system_clock::now().time_since_epoch().count());
}
