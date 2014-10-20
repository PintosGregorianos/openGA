//---------------------------------------------------------------------------

#pragma once

#include "dna.hpp"
#include "error.hpp"
#include "rand.hpp"

//---------------------------------------------------------------------------

class crossover {
    public:
        static void typeA(dna &first, dna &second);
        static void typeB(dna &first, dna &second);
        static void typeC(dna &first, dna &second);

        //novas funções de crossover
        //as anteriores serão mantidas temporariamente
        //por uma questão de compatibilidade
        void typeA(dna &dad, dna &mom, dna &son, dna &doughter);
        void typeB(dna &dad, dna &mom, dna &son, dna &doughter);
        void typeC(dna &dad, dna &mom, dna &son, dna &doughter);

    private:
        static void cross(dna &first, dna &second, unsigned int mask);

        void cross(dna &dad, dna &mom, unsigned int mask, dna &son, dna &doughter);
};

//---------------------------------------------------------------------------




