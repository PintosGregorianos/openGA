#include "dna.hpp"
#include "rand.hpp"

void dna::create(unsigned short int n_chroms) {
    chromossomes.resize(n_chroms);
    for (std::size_t i = 0; i < chromossomes.size(); i++) chromossomes[i] = uint_rand();
}

void dna::setChromossome(unsigned short int chrom_index, unsigned int value){
    chromossomes[chrom_index]=value;
}

unsigned int dna::getChromossome(unsigned short int chrom_index) const {
	return chromossomes[chrom_index];
}

float dna::getChromossomeAsReal(unsigned short int chrom_index) const {
	return (float)chromossomes[chrom_index]/((float)(~(unsigned int)0));
}

const unsigned int *dna::getChromossomes() const {
	return &chromossomes.front();
}

