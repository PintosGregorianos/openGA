#pragma once

#include "population.hpp"
#include "simulation.hpp"

#include "engine_parameters.hpp"

class engine {
    protected:
        engine_parameters eng_params;

        population *p_population;
        simulation *p_simulation;

        void bindParams(population *the_population,simulation *the_simulation);

        virtual void startEngine   (void) = 0;

        virtual void makeElitism   (unsigned short int n_elitists) = 0;
		virtual void makeSelection (unsigned short int selection_start_point) = 0;
		virtual void makeCrossover (unsigned short int n_cross) = 0;
		virtual void makeMutation  (unsigned short int n_mutat) = 0;
        virtual void manageGoals   (void) = 0;

        virtual void stepEngine    (void) = 0;

};
