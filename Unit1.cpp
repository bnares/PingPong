//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



int paletka =10;
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

    //przegrana

    if((Image3 ->Left<= Image1 ->Left-30) ||
    (Image3 -> Left  >= Image2->Left +Image2->Width-10))
    {

     Timer1 -> Enabled =false;
     Button1 ->Visible = true;

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
      Image3 ->Left =448;
      Image3 ->Top = 240;
      Timer1 ->Enabled =true;
      Button1 ->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawyGoraTimer(TObject *Sender)
{
  if(Image2 ->Top>=3)
  {
  Image2 ->Top -=10;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawyDolTimer(TObject *Sender)
{
  if(Image2->Top+Image2 -> Height <=Shape1->Height-3)
  {
  Image2 ->Top +=10;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP)
    {
      prawyGora ->Enabled =true;
    }

    if(Key == VK_DOWN)
    {
     prawyDol ->Enabled =true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key == VK_UP)
    {
      prawyGora ->Enabled =false;
    }

    if(Key == VK_DOWN)
    {
     prawyDol ->Enabled =false;
    }
}
//---------------------------------------------------------------------------
