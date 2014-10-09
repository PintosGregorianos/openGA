#include "simulation.hpp"

simulation::simulation() {
    params.cross_scale   = 1.f;
    params.mutat_scale   = 1.f;
    params.elitism_scale = 1.f;

    achieved_goals = goals::none;
}

void simulation::setCrossoverProbability(const float probability) {
	if (probability >= 0.f and probability <= 1.f)
		params.cross_prob = probability;
	else {
		params.cross_prob = 0.f;
		PRINT_ERROR("setCrossoverProbability()\n\tNegative or higher than 1.f probability.\n");
	}
}

void simulation::setMutationProbability(const float probability) {
	if (probability >= 0.f and probability <= 1.f)
		params.mutat_prob = probability;
	else {
		params.mutat_prob = 0.f;
		PRINT_ERROR("setMutationProbability()\n\tNegative or higher than 1.f probability.\n");
	}
}

void simulation::setElitismRatio(const float ratio) {
	if (ratio >= 0.f and ratio <= 1.f)
		params.elitism_ratio = ratio;
	else {
		params.elitism_ratio = 0.f;
		PRINT_ERROR("setElitismRatio()\n\tNegative or higher than 1.f ratio.\n");
	}
}

void simulation::setCrossoverScaleFactor(float scale_factor) {
	if (scale_factor > 0.f) {
		params.cross_scale = scale_factor;
	}
	else {
		params.cross_scale = 1.f;
		PRINT_ERROR("setcrossoverScaleFactor()\n\tNegative scale factor. Factor set to 1.0.\n");
	}
}

void simulation::setMutationScaleFactor(float scale_factor) {
	if (scale_factor > 0.f) {
		params.mutat_scale = scale_factor;
	}
	else {
		params.mutat_scale = 1.f;
		PRINT_ERROR("setMutationScaleFactor()\n\tNegative scale factor. Factor set to 1.0.\n");
	}
}

void simulation::setElitismScaleFactor(float scale_factor) {
	if (scale_factor > 0.f) {
		params.elitism_scale = scale_factor;
	}
	else {
		params.elitism_scale = 1.f;
		PRINT_ERROR("setElitismScaleFactor()\n\tNegative scale factor. Factor set to 1.0.\n");
	}
}

void simulation::setGoalDivergence(float divergence) {
	if (divergence > 0.f)
		params.diverg_goal = divergence;
	else {
		params.diverg_goal = 0.f;
		PRINT_ERROR("setGoalDivergence()\n\tNegative target divergence.\n");
	}
}

void simulation::setGoalGeneration(unsigned short int generation) {
	if (generation > 0)
		params.gen_goal = generation;
	else {
		params.gen_goal = 0;
		PRINT_ERROR("setGoalGeneration()\n\tNegative or zero target generation.\n");
	}
}

void simulation::setCrossoverType(crossover_type type) {
    params.cross_type = type;
}

float simulation::getCrossoverProbability(void) const {
	return params.cross_prob;
}

float simulation::getMutationProbability(void) const {
	return params.mutat_prob;
}

float simulation::getElitismRatio(void) const {
	return params.elitism_ratio;
}

void simulation::setGoals(unsigned short int goal) {
	params.goal = goal;
}

unsigned short int simulation::getGoals(void) const {
	return params.goal;
}

float simulation::getGoalDivergence(void) const {
	return params.diverg_goal;
}

unsigned short int simulation::getGoalGeneration(void) const {
	return params.gen_goal;
}

float simulation::getCrossoverScaleFactor(void) const {
	return params.cross_scale;
}

float simulation::getMutationScaleFactor(void) const {
	return params.mutat_scale;
}

float simulation::getElitismScaleFactor(void) const {
	return params.elitism_scale;
}

crossover_type simulation::getCrossoverType(void) const {
    return params.cross_type;
}

unsigned short int simulation::getAchievedGoals() const {
    return achieved_goals;
}
