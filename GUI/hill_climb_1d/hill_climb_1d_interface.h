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
#include "openga_wrapper.h"

//---------------------------------------------------------------------------

#define DEFAULT_FILE_NAME           "default.dat"
#define FLOAT_PRECISION             6

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
   void __fastcall edPopSizeChange(TObject *Sender);
   void __fastcall edDNASizeChange(TObject *Sender);
   void __fastcall cbCromTypeChange(TObject *Sender);
   void __fastcall cbCrossTypeChange(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall edCrossProbChange(TObject *Sender);
   void __fastcall edMutProbChange(TObject *Sender);
   void __fastcall edElitimsRatioChange(TObject *Sender);
   void __fastcall edCrossScaleChange(TObject *Sender);
   void __fastcall edMutScaleChange(TObject *Sender);
   void __fastcall edElitimsScaleChange(TObject *Sender);
private:	// User declarations

   openga_wrapper openGA;

   canvas_plot_thread *plot_t;

   void initialize(void);

   ga_config loadFile(AnsiString filename);
   void saveFile(AnsiString filename, ga_config config);

   void updateUI(void);

public:		// User declarations
   __fastcall TfmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
//---------------------------------------------------------------------------
#endif
