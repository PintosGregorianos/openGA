#include "thread_engine.hpp"

thread_engine::thread_engine() : configured(false), current_status(thread_engine_status::stopped) {}

thread_engine_status thread_engine::getStatus(void) const {
    return current_status;
}

void thread_engine::setFitnessCallback(float(*callback)(const dna &)) {
    if (current_status != thread_engine_status::running and current_status != thread_engine_status::wait_pause) {
        engine.setFitnessCallback(callback);
    }
}

void thread_engine::configEngine(population &the_population,simulation &the_simulation) {
    if (current_status != thread_engine_status::running and current_status != thread_engine_status::wait_pause) {
        engine.configEngine(the_population,the_simulation);
        this->the_simulation = &the_simulation;
        configured = true;
    }
}

void thread_engine::start(void) {
    if (!configured) {
        PRINT_ERROR("Thread Engine: Can't start engine before configuration. Read configEngine(...)");
        return;
    }
    if (current_status == thread_engine_status::stopped or current_status == thread_engine_status::paused) {
        // começa a thread
        my_thread = std::thread(&thread_engine::process,this);
        current_status = thread_engine_status::running;
    }
}

///THREAD
//-----------------------------------------------------------------------------------
void thread_engine::process(void) {
    /* se o cara não definir algum goal a thread vai rodar pra sempre!*//// problema?
    while (the_simulation->getAchievedGoals() == goals::none) {
        my_mutex.lock();
        if (current_status == thread_engine_status::wait_pause) {
            current_status = thread_engine_status::paused;
            break;
        }
        if (current_status == thread_engine_status::stopped) break;
        my_mutex.unlock();

        // roda o motor
        engine.stepEngine();

        // copia a simulação pro alias sincronizado
        alias_simulation = *the_simulation;
    }
}
//-------------------------------------------------------------------------------------

void thread_engine::pause(void) {
    if (current_status != thread_engine_status::running) return;
    my_mutex.lock();
    current_status = thread_engine_status::wait_pause;
    my_mutex.unlock();
}

void thread_engine::syncedPause(void) {
    pause();
    while(current_status != thread_engine_status::paused);
}

void thread_engine::stop(void) {
    if (current_status != thread_engine_status::running or current_status != thread_engine_status::paused) return;
    my_mutex.lock();
    current_status = thread_engine_status::stopped;
    my_mutex.unlock();

    // aguarda a thread acabar
    my_thread.join();
}

const simulation & thread_engine::acessSyncedSimulation(void) const {
    return alias_simulation;
}

