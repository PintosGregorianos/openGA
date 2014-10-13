//---------------------------------------------------------------------------

#ifndef hill_climb_1d_interfaceH
#define hill_climb_1d_interfaceH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "canvas_plot_thread.h"

//---------------------------------------------------------------------------

class TfmMain : public TForm
{
__published:	// IDE-managed Components
   TGroupBox *gbGAConfig;
   TLabeledEdit *edPopSize;
   TLabeledEdit *edDNASize;
   TLabeledEdit *edCrossProb;
   TLabeledEdit *edElitimsRatio;
   TLabeledEdit *edMutProb;
   TLabeledEdit *edCrossScale;
   TLabeledEdit *edMutScale;
   TLabeledEdit *edElitimsScale;
   TLabel *lbCrossType;
   TComboBox *cbCrossType;
   TLabel *Label1;
   TComboBox *cbCromType;
   TButton *Button1;
   TButton *Button2;
   TImage *imPlot;
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall FormResize(TObject *Sender);
private:	// User declarations

   canvas_plot_thread *plot_t;

   void initialize(void);

public:		// User declarations
   __fastcall TfmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
//---------------------------------------------------------------------------
#endif
