#include "rand.hpp"
#include <iostream>
#include <bitset>

int main() {
    seed_from_time();
    unsigned int n1 = (1 << (uint_rand()%32)) - 1;
    unsigned int n2 = (1 << (uint_rand()%32)) - 1;

    unsigned int n3 = n1^n2;

    std::bitset<32> b1(n1),b2(n2),b3(n3);

    std::cout << b1 << std::endl << b2 << std::endl << b3;

    return 0;
}
