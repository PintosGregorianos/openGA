//---------------------------------------------------------------------------

#include "crossover.hpp"

//---------------------------------------------------------------------------

// máscara no estilo 00000000000111111111111111111
void crossover::typeA(dna &first, dna &second) {
    #ifdef DEBUG_MODE
    if (first.chromossomes.size() != second.chromossomes.size())
        PRINT_ERROR("Atempt to crossover diferent size DNAs");
    #endif // DEBUG_MODE

    unsigned int mask = (1 << (uint_rand()%32)) - 1;
    cross(first, second, mask);
}

//---------------------------------------------------------------------------

// máscara no estilo 00000001111111111111110000000
void crossover::typeB(dna &first, dna &second) {
    #ifdef DEBUG_MODE
    if (first.chromossomes.size() != second.chromossomes.size())
        PRINT_ERROR("Atempt to crossover diferent size DNAs");
    #endif // DEBUG_MODE

    unsigned int mask = ((1 << (uint_rand()%32)) - 1)^((1 << (uint_rand()%32)) - 1);
    cross(first, second, mask);
}

//---------------------------------------------------------------------------

// máscara no estilo 010100111010110010111010110
// distribuição (aproximada) de 50% zeros e 50% uns
// essa é a implementação tosca, que não garante 50% de zeros e uns
void crossover::typeC(dna &first, dna &second) {
    #ifdef DEBUG_MODE
    if (first.chromossomes.size() != second.chromossomes.size())
        PRINT_ERROR("Atempt to crossover diferent size DNAs");
    #endif // DEBUG_MODE

    unsigned int mask = uint_rand();
    cross(first, second, mask);
}

//---------------------------------------------------------------------------

//função de crossover primária
//todas as outras chamam essa (estamos trabalhando nisso)
//em caso de bug, culpar o Pinto
void crossover::cross(dna &first, dna &second, unsigned int mask){
    unsigned int temp;
    auto b = second.chromossomes.begin();
    for (auto a = first.chromossomes.begin(); a != first.chromossomes.end(); a++,b++) {
        temp = *a;
        *a = (*b   & mask) | (*a & ~mask);
        *b = (temp & mask) | (*b & ~mask);
    }
}

//---------------------------------------------------------------------------



