#pragma once

#include "simulation_parameters.hpp"

#include "error.hpp"

class simulation {
    friend class single_engine;
    protected:
        simulation_parameters params;

        goals achieved_goals;

    public:
        void setcrossoverProbability (const float probability);
		void setMutationProbability  (const float probability);
		void setElitismRatio         (const float ration);
		void setcrossoverScaleFactor (float scale_factor);
		void setMutationScaleFactor  (float scale_factor);
		void setElitismScaleFactor   (float scale_factor);
		void setCrossoverType        (crossover_type type);

		float getcrossoverProbability  (void) const;
		float getMutationProbability   (void) const;
		float getElitismRatio          (void) const;
		float getcrossoverScaleFactor  (void) const;
		float getMutationScaleFactor   (void) const;
		float getElitismScaleFactor    (void) const;
		crossover_type getCrossoverType(void) const;

		void setGoals(goals goal);

		goals getGoals        (void) const;
		goals getAchievedGoals(void) const;

		void setGoalDivergence (float divergence);
		void setGoalGeneration (unsigned short int generation);

		float              getGoalDivergence(void) const;
		unsigned short int getGoalGeneration(void) const;
};
