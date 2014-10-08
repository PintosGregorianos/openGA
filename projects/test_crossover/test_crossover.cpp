#include "crossover.hpp"
#include <iostream>
#include <bitset>

int main() {
    crossover co;
    dna d1(1), d2(1);

    seed_from_time();

    unsigned int n1 = d1.getChromossome(0);
    unsigned int n2 = d2.getChromossome(0);

    co.typeC(d1, d2);

    unsigned int n3 = d1.getChromossome(0);
    unsigned int n4 = d2.getChromossome(0);

    std::bitset<32> b1(n1),b2(n2),b3(n3),b4(n4);

    std::cout << b1 << std::endl << b2 << std::endl << std::endl << b3 << std::endl << b4;

    return 0;
}
