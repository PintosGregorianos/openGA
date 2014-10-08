#pragma once

#include "individual.hpp"

class individual_comp {
    public:
        bool operator()(individual *first,individual *second);
};
