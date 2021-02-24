//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "CGAUGES.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Shape1;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TTimer *Timer1;
        TTimer *prawyGora;
        TTimer *prawyDol;
        TButton *Button1;
        TTimer *lewyDol;
        TTimer *lewyGora;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *Button2;
        TButton *Button3;
        TCGauge *CGauge1;
        TCGauge *CGauge2;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall prawyGoraTimer(TObject *Sender);
        void __fastcall prawyDolTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall lewyDolTimer(TObject *Sender);
        void __fastcall lewyGoraTimer(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
