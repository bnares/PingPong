//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x =-5;
int y = -5;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    Image3 -> Left +=x;
    Image3 -> Top +=y;
    //bok gora
    if(Image3 -> Top <=3)
    {
      y = y*-1;
    }

    //bok lewy
    if(Image3 -> Left <= 3)
    {
      x = x*-1;
    }

    //bok dol

    if(Image3 -> Top + Image3 -> Height >= Shape1 ->Height -5)
    {
      y = y*-1;
    }

    //bok prawy

    if(Image3->Left + Image3-> Width >= Shape1 ->Width-5)
    {
      x = x*-1;
    }
}
//---------------------------------------------------------------------------
 