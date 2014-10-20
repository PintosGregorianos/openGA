//---------------------------------------------------------------------------

#include "openga_wrapper.h"

//---------------------------------------------------------------------------

openga_wrapper::openga_wrapper(){
   //ver com o gregório
   sim.setGoalGeneration(1000);
   sim.setGoals(goals::generation);
   sim.setSelectionType(selection_types::roulette::linearFitness);
}

//---------------------------------------------------------------------------

openga_wrapper::~openga_wrapper(){
}

//---------------------------------------------------------------------------

void openga_wrapper::setPopulationSize(const unsigned int size){
   pop.setPopulationSize(size);
   config.pop_size=size;
}

//---------------------------------------------------------------------------

void openga_wrapper::setDNASize(const unsigned int size){
   pop.setDNADimension(size);
   config.dna_size=size;
}

//---------------------------------------------------------------------------

void openga_wrapper::setCromossomeType(cromossome_type_e type){
   config.cromo_type=type;
}

//---------------------------------------------------------------------------

void openga_wrapper::setCrossoverProbability(const float probability){
   sim.setCrossoverProbability(probability);
   config.cross_prob=probability;
}

//---------------------------------------------------------------------------

void openga_wrapper::setMutationProbability(const float probability){
   sim.setMutationProbability(probability);
   config.mutation_prob=probability;
}

//---------------------------------------------------------------------------

void openga_wrapper::setElitismRatio(const float ratio){
   sim.setElitismRatio(ratio);
   config.elitism_ratio=ratio;
}

//---------------------------------------------------------------------------

void openga_wrapper::setCrossoverScaleFactor(float scale_factor){
   sim.setCrossoverScaleFactor(scale_factor);
   config.cross_scale=scale_factor;
}

//---------------------------------------------------------------------------

void openga_wrapper::setMutationScaleFactor(float scale_factor){
   sim.setMutationScaleFactor(scale_factor);
   config.mutation_scale=scale_factor;
}

//---------------------------------------------------------------------------

void openga_wrapper::setElitismScaleFactor(float scale_factor){
   sim.setElitismScaleFactor(scale_factor);
   config.elitism_scale=scale_factor;
}

//---------------------------------------------------------------------------

void openga_wrapper::setCrossoverType(crossover_type type){
   sim.setCrossoverType(type);
   config.cross_type=type;
}

//---------------------------------------------------------------------------

unsigned int openga_wrapper::getPopulationSize(void){
   return config.pop_size;
}

//---------------------------------------------------------------------------

unsigned int openga_wrapper::getDNASize(void){
   return config.dna_size;
}

//---------------------------------------------------------------------------

cromossome_type_e openga_wrapper::getCromossomeType(void){
   return config.cromo_type;
}

//---------------------------------------------------------------------------

float openga_wrapper::getCrossoverProbability(void){
   return config.cross_prob;
}

//---------------------------------------------------------------------------

float openga_wrapper::getMutationProbability(void){
   return config.mutation_prob;
}

//---------------------------------------------------------------------------

float openga_wrapper::getElitismRatio(void){
   return config.elitism_ratio;
}

//---------------------------------------------------------------------------

float openga_wrapper::getCrossoverScaleFactor(void){
   return config.cross_scale;
}

//---------------------------------------------------------------------------

float openga_wrapper::getMutationScaleFactor(void){
   return config.mutation_scale;
}

//---------------------------------------------------------------------------

float openga_wrapper::getElitismScaleFactor(void){
   return config.elitism_scale;
}

//---------------------------------------------------------------------------

crossover_type openga_wrapper::getCrossoverType(void){
   return config.cross_type;
}

//---------------------------------------------------------------------------

void openga_wrapper::setGAConfig(ga_config cfg){
   config=cfg;
}

//---------------------------------------------------------------------------

ga_config openga_wrapper::getGAConfig(void){
   return config;
}

//---------------------------------------------------------------------------

void openga_wrapper::setFitnessCallback(FitnessCallbackPtr cb, void *p){
   eng.setFitnessCallback(cb, p);
}

//---------------------------------------------------------------------------

void openga_wrapper::setIterationCallback(IterationCallbackPtr cb, void *p){
   iteration_callback=cb;
   iteration_inst_callback=p;
}

//---------------------------------------------------------------------------

void openga_wrapper::start(void){
   eng.configEngine(pop, sim);

   /*while(sim.getAchievedGoals()!=goals::generation){
      eng.stepEngine();
      iteration_callback(iteration_inst_callback);
   }*/
   running=true;
   step();
}

//---------------------------------------------------------------------------

void openga_wrapper::step(void){
   if (running){
      eng.stepEngine();
      iteration_callback(iteration_inst_callback);
   }
}

//---------------------------------------------------------------------------

void openga_wrapper::stop(void){
   running=false;
}

//---------------------------------------------------------------------------

float openga_wrapper::getChromossomeAsReal(unsigned short int individual_index, unsigned short int chrom_index){
   dna individual_dna;

   individual_dna=pop.acessIndividualDNA(individual_index);
   return individual_dna.getChromossomeAsReal(chrom_index);
}

//---------------------------------------------------------------------------

float openga_wrapper::getIndividualFitness(unsigned short int individual_index){
   return pop.getIndividualFitness(individual_index);
}

//---------------------------------------------------------------------------





