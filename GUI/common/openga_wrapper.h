//---------------------------------------------------------------------------

#ifndef openga_wrapperH
#define openga_wrapperH

//---------------------------------------------------------------------------

#include "crossover_type.hpp"

//---------------------------------------------------------------------------

enum class cromossome_type_e{
    ct_byte,
    ct_signedInt,
    ct_unsignedInt,
    ct_float,
    ct_double
};

//estrutura de configuração do GA
struct ga_config{
   unsigned int pop_size;
   unsigned int dna_size;
   cromossome_type_e cromo_type;
   crossover_type cross_type;
   float cross_prob;
   float mutation_prob;
   float elitism_ratio;
   float cross_scale;
   float mutation_scale;
   float elitism_scale;
};

//---------------------------------------------------------------------------

class openga_wrapper{
   public:

      openga_wrapper();
      ~openga_wrapper();

      //SETs
      void setPopulationSize(const unsigned int size);
      void setDNASize(const unsigned int size);
      void setCromossomeType(cromossome_type_e type);
      void setCrossoverProbability(const float probability);
      void setMutationProbability(const float probability);
      void setElitismRatio(const float ratio);
      void setCrossoverScaleFactor(float scale_factor);
      void setMutationScaleFactor(float scale_factor);
      void setElitismScaleFactor(float scale_factor);
      void setCrossoverType(crossover_type type);

      //GETs
      unsigned int getPopulationSize(void);
      unsigned int getDNASize(void);
      cromossome_type_e getCromossomeType(void);
      float getCrossoverProbability(void);
      float getMutationProbability(void);
      float getElitismRatio(void);
      float getCrossoverScaleFactor(void);
      float getMutationScaleFactor(void);
      float getElitismScaleFactor(void);
      crossover_type getCrossoverType(void);

      void setGAConfig(ga_config cfg);
      ga_config getGAConfig(void);

   private:

      ga_config config;
};

//---------------------------------------------------------------------------
#endif
