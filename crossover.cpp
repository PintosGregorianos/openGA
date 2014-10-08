#include "crossover.hpp"

// máscara no estilo 00000000000111111111111111111
void crossover::typeA(dna &first, dna &second) {
    #ifdef DEBUG_MODE
    if (first.chromossomes.size() != second.chromossomes.size())
        PRINT_ERROR("Atempt to crossover diferent size DNAs");
    #endif // DEBUG_MODE

    unsigned int temp,mask = (1 << (uint_rand()%32)) - 1;
    auto b = second.chromossomes.begin();
    for (auto a = first.chromossomes.begin(); a != first.chromossomes.end(); a++,b++) {
        temp = *a;
        *a = (*b   & mask) | (*a & ~mask);
        *b = (temp & mask) | (*b & ~mask);
    }
}

// máscara no estilo 00000001111111111111110000000
void crossover::typeB(dna &first, dna &second) {
    #ifdef DEBUG_MODE
    if (first.chromossomes.size() != second.chromossomes.size())
        PRINT_ERROR("Atempt to crossover diferent size DNAs");
    #endif // DEBUG_MODE

    unsigned int temp,mask = ((1 << (uint_rand()%32)) - 1)^((1 << (uint_rand()%32)) - 1);
    auto b = second.chromossomes.begin();
    for (auto a = first.chromossomes.begin(); a != first.chromossomes.end(); a++,b++) {
        temp = *a;
        *a = (*b   & mask) | (*a & ~mask);
        *b = (temp & mask) | (*b & ~mask);
    }
}

// IMPLEMENTAR!!!!!!!!!! PINTO! PINTO! PINTO!
// máscara no estilo 010100111010110010111010110
// distribuição de 50% zeros e 50% uns
void crossover::typeC(dna &first, dna &second) {


}
