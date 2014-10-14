//---------------------------------------------------------------------------

#include "openga_wrapper.h"

//---------------------------------------------------------------------------

openga_wrapper::openga_wrapper(){
}

//---------------------------------------------------------------------------

openga_wrapper::~openga_wrapper(){
}

//---------------------------------------------------------------------------

void openga_wrapper::setPopulationSize(const unsigned int size){
   config.pop_size=size;
}

//---------------------------------------------------------------------------

void openga_wrapper::setDNASize(const unsigned int size){
   config.dna_size=size;
}

//---------------------------------------------------------------------------

void openga_wrapper::setCromossomeType(cromossome_type_e type){
   config.cromo_type=type;
}

//---------------------------------------------------------------------------

void openga_wrapper::setCrossoverProbability(const float probability){
   config.cross_prob=probability;
}

//---------------------------------------------------------------------------

void openga_wrapper::setMutationProbability(const float probability){
   config.mutation_prob=probability;
}

//---------------------------------------------------------------------------

void openga_wrapper::setElitismRatio(const float ratio){
   config.elitism_ratio=ratio;
}

//---------------------------------------------------------------------------

void openga_wrapper::setCrossoverScaleFactor(float scale_factor){
   config.cross_scale=scale_factor;
}

//---------------------------------------------------------------------------

void openga_wrapper::setMutationScaleFactor(float scale_factor){
   config.mutation_scale=scale_factor;
}

//---------------------------------------------------------------------------

void openga_wrapper::setElitismScaleFactor(float scale_factor){
   config.elitism_scale=scale_factor;
}

//---------------------------------------------------------------------------

void openga_wrapper::setCrossoverType(crossover_type type){
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





