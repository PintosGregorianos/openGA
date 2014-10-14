//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hill_climb_1d_interface.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TfmMain *fmMain;

//---------------------------------------------------------------------------
__fastcall TfmMain::TfmMain(TComponent* Owner)
   : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void TfmMain::initialize(void){
   plot_t=new canvas_plot_thread(false);
   plot_t->period=20;
   plot_t->addCanvas(imPlot->Canvas, imPlot->Height, imPlot->Width);

   openGA.setGAConfig(loadFile(DEFAULT_FILE_NAME));
   updateUI();
}

//---------------------------------------------------------------------------

ga_config TfmMain::loadFile(AnsiString filename){
   FILE *fpointer=NULL;
   union file_stream{
      ga_config file;
      char raw[sizeof(ga_config)];
   } data;

   fpointer=fopen(filename.c_str(), "rb");
   fread(&data.raw, 1, sizeof(ga_config), fpointer);
   fclose(fpointer);

   return data.file;
}

//---------------------------------------------------------------------------

void TfmMain::saveFile(AnsiString filename, ga_config config){
   FILE *fpointer=NULL;
   union file_stream{
      ga_config file;
      char raw[sizeof(ga_config)];
   } data;

   data.file=config;

   fpointer=fopen(filename.c_str(), "wb");
   fwrite(&data.raw, 1, sizeof(ga_config), fpointer);
   fclose(fpointer);
}

//---------------------------------------------------------------------------

void TfmMain::updateUI(void){
   cromossome_type_e cromo_type;
   crossover_type cross_type;

   edPopSize->Text=IntToStr((int)openGA.getPopulationSize());
   edDNASize->Text=IntToStr((int)openGA.getDNASize());

   cromo_type=openGA.getCromossomeType();
   switch (cromo_type){
      case cromossome_type_e::ct_byte: cbCromType->ItemIndex=0; break;
      case cromossome_type_e::ct_signedInt: cbCromType->ItemIndex=1; break;
      case cromossome_type_e::ct_unsignedInt: cbCromType->ItemIndex=2; break;
      case cromossome_type_e::ct_float: cbCromType->ItemIndex=3; break;
      case cromossome_type_e::ct_double: cbCromType->ItemIndex=4; break;
   }

   cross_type=openGA.getCromossomeType();
   switch (cross_type){
      case crossover_type::onePoint: cbCrossType->ItemIndex=0; break;
      case crossover_type::twoPoint: cbCrossType->ItemIndex=1; break;
      case crossover_type::cutSplice: cbCrossType->ItemIndex=2; break;
   }

   edCrossProb->Text=FloatToStrF(openGA.getCrossoverProbability(), ffGeneral, FLOAT_PRECISION, FLOAT_PRECISION);
   edMutProb->Text=FloatToStrF(openGA.getMutationProbability(), ffGeneral, FLOAT_PRECISION, FLOAT_PRECISION);
   edElitimsRatio->Text=FloatToStrF(openGA.getElitismRatio(), ffGeneral, FLOAT_PRECISION, FLOAT_PRECISION);

   edCrossScale->Text=FloatToStrF(openGA.getCrossoverScaleFactor(), ffGeneral, FLOAT_PRECISION, FLOAT_PRECISION);
   edMutScale->Text=FloatToStrF(openGA.getMutationScaleFactor(), ffGeneral, FLOAT_PRECISION, FLOAT_PRECISION);
   edElitimsScale->Text=FloatToStrF(openGA.getElitismScaleFactor(), ffGeneral, FLOAT_PRECISION, FLOAT_PRECISION);
}

//---------------------------------------------------------------------------

void __fastcall TfmMain::FormCreate(TObject *Sender)
{
   initialize();
}

//---------------------------------------------------------------------------

void __fastcall TfmMain::FormResize(TObject *Sender)
{
   imPlot->Picture->Bitmap->Width=imPlot->ClientWidth;
   imPlot->Picture->Bitmap->Height=imPlot->ClientHeight;
   plot_t->resizePlot(0, imPlot->Height, imPlot->Width);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::edPopSizeChange(TObject *Sender)
{
   openGA.setPopulationSize(StrToInt(edPopSize->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::edDNASizeChange(TObject *Sender)
{
   openGA.setDNASize(StrToInt(edDNASize->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::cbCromTypeChange(TObject *Sender)
{
   cromossome_type_e type;

   switch (cbCromType->ItemIndex){
      case 0: type=cromossome_type_e::ct_byte; break;
      case 1: type=cromossome_type_e::ct_signedInt; break;
      case 2: type=cromossome_type_e::ct_unsignedInt; break;
      case 3: type=cromossome_type_e::ct_float; break;
      case 4: type=cromossome_type_e::ct_double; break;
   }

   openGA.setCromossomeType(type);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::cbCrossTypeChange(TObject *Sender)
{
   crossover_type type;

   switch (cbCrossType->ItemIndex){
      case 0: type=crossover_type::onePoint; break;
      case 1: type=crossover_type::twoPoint; break;
      case 2: type=crossover_type::cutSplice; break;;
   }

   openGA.setCrossoverType(type);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
   saveFile(DEFAULT_FILE_NAME, openGA.getGAConfig());
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::edCrossProbChange(TObject *Sender)
{
   try{
      openGA.setCrossoverProbability(StrToFloat(edCrossProb->Text));
   }
   catch(EConvertError *e){}
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::edMutProbChange(TObject *Sender)
{
   try{
      openGA.setMutationProbability(StrToFloat(edMutProb->Text));
   }
   catch(EConvertError *e){}
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::edElitimsRatioChange(TObject *Sender)
{
   try{
      openGA.setElitismRatio(StrToFloat(edElitimsRatio->Text));
   }
   catch(EConvertError *e){}
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::edCrossScaleChange(TObject *Sender)
{
   try{
      openGA.setCrossoverScaleFactor(StrToFloat(edCrossScale->Text));
   }
   catch(EConvertError *e){}
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::edMutScaleChange(TObject *Sender)
{
   try{
      openGA.setMutationScaleFactor(StrToFloat(edMutScale->Text));
   }
   catch(EConvertError *e){}
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::edElitimsScaleChange(TObject *Sender)
{
   try{
      openGA.setElitismScaleFactor(StrToFloat(edElitimsScale->Text));
   }
   catch(EConvertError *e){}
}
//---------------------------------------------------------------------------

