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

