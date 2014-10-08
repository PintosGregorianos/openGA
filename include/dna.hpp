#pragma once

#include <vector>

typedef std::vector<unsigned int> chrom_container;

class dna {
    protected:
    	chrom_container chromossomes;

        chrom_container mutate(void);
        chrom_container crossover(dna &other);

    public:
        void create(unsigned short int n_chroms);

        unsigned int       getChromossome      (unsigned short int chrom_index) const;
        float              getChromossomeAsReal(unsigned short int chrom_index) const;
        const unsigned int *getChromossomes    (void) const;



    friend class population;
    friend class crossover;
    friend class mutation;
};
