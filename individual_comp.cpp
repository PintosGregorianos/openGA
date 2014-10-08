#include "individual_comp.hpp"

bool individual_comp::operator()(individual *first,individual *second) {
    return first->fitness < second->fitness;
}

