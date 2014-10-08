#pragma once

#include "dna.hpp"
#include "error.hpp"
#include "rand.hpp"

class crossover {
    public:
        static void typeA(dna &first, dna &second);
        static void typeB(dna &first, dna &second);
        static void typeC(dna &first, dna &second);
};


