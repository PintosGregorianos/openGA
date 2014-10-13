//---------------------------------------------------------------------------

#ifndef hill_climb_1d_interfaceH
#define hill_climb_1d_interfaceH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
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
   TComboBox *ComboBox1;
   TButton *Button1;
   TButton *Button2;
private:	// User declarations
public:		// User declarations
   __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
