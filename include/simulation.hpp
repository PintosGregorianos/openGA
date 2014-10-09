#pragma once

#include "simulation_parameters.hpp"

#include "error.hpp"

class simulation {
    friend class single_engine;
    protected:
        simulation_parameters params;

        unsigned short int achieved_goals;

    public:
        simulation();

        void setCrossoverProbability (const float probability);
		void setMutationProbability  (const float probability);
		void setElitismRatio         (const float ration);
		void setCrossoverScaleFactor (float scale_factor);
		void setMutationScaleFactor  (float scale_factor);
		void setElitismScaleFactor   (float scale_factor);
		void setCrossoverType        (crossover_type type);

		float getCrossoverProbability  (void) const;
		float getMutationProbability   (void) const;
		float getElitismRatio          (void) const;
		float getCrossoverScaleFactor  (void) const;
		float getMutationScaleFactor   (void) const;
		float getElitismScaleFactor    (void) const;
		crossover_type getCrossoverType(void) const;

		void setGoals(unsigned short int goal);

		unsigned short int getGoals        (void) const;
		unsigned short int getAchievedGoals(void) const;

		void setGoalDivergence (float divergence);
		void setGoalGeneration (unsigned short int generation);

		float              getGoalDivergence(void) const;
		unsigned short int getGoalGeneration(void) const;
};
