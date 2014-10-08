#pragma once

#define DEBUG_MODE

#include "error.hpp"

#include "individual.hpp"
#include "individual_comp.hpp"

#include "dna.hpp"
#include "rand.hpp"
#include "goals.hpp"
#include "population_parameters.hpp"

#include <vector>
#include <algorithm>
#include <cmath>


typedef std::vector<individual*> individual_container;


class population {
    friend class single_engine;
	protected:
	    population_parameters params;

		unsigned short int gen_counter;

		float *diverg;

		individual_container individuals;

        void increase_gen(void);

        void populate(void);

	public:
		population();
		~population();

		void setPopulationSize(unsigned short int size);
		void setDNADimension  (unsigned short int dimension);

		unsigned short int getPopulationSize(void) const;
		unsigned short int getDNADimension  (void) const;

		void updatePopulationFitness(float const *fitness_vector);
		void updateindividualFitness(unsigned short int individual_id, float fitnenss);
		void updateAllFitness       (float fitness);
		void resetFitness           (void);

		float              getindividualFitness(unsigned short int individual_id) const;
		std::vector<float> getPopulationFitness(void) const;

		const dna& acessIndividualDNA (unsigned short int individual_id) const;
		dna getIndividualDNA          (unsigned short int individual_id) const;

		unsigned short int getActualGeneration(void) const;

		void         calcDivergence(void);
		float        getDivergence (unsigned short int chrom_id) const;
		const float *getDivergences(void) const;

};
