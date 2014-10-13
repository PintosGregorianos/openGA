#pragma once

#include <thread>
#include <mutex>
#include "single_engine.hpp"
#include "dna.hpp"
#include "error.hpp"

enum class thread_engine_status {
    running,paused,stopped,wait_pause,goal_achieved
};

class thread_engine {
    private:
        // motor de trabalho
        single_engine engine;

        // thread e mutex pra sincronismo
        std::thread my_thread;
        std::mutex  my_mutex;

        simulation *the_simulation;

        // alias da simula��o sincronizado a casa step
        simulation  alias_simulation;



        volatile thread_engine_status current_status;
        volatile bool configured;

        // fun��o que roda em thread
        void process(void);

    public:
        thread_engine();

        void start(void);

        // pede pra pausar o motor mas continua firme e forte
        void pause(void);

        // pausa o motor, tranca, e aguarda at� o fim da atual itera��o
        void syncedPause(void);

        void stop(void);

        // configura engine e linka com a popula��o e simula��o
        void configEngine(population &the_population,simulation &the_simulation);

        // tive que reescrever essa, me parece meio burro
        void setFitnessCallback(float(*callback)(const dna &));

        // retorna o thread_engine_status atual da thread_engine
        thread_engine_status getStatus() const;

        // retorna uma referencia constante pro alias da simula��o
        // essa � uma copia segura da simula��o que pode ser acessada com a thread rodando
        const simulation& acessSyncedSimulation(void) const;
};
