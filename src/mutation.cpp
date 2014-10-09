#include "mutation.hpp"

void mutation::typeA(dna &first) {
    unsigned int mask = uint_rand();
    for (auto a = first.chromossomes.begin(); a != first.chromossomes.end(); a++) {
        *a ^= mask;
    }
}
