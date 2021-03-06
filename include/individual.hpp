#pragma once

#include "dna.hpp"

class individual {
    protected:
        float fitness;
        dna *my_dna;

    public:
        individual();
        ~individual();

    friend class individual_comp;
    friend class population;
    friend class single_engine;
};
