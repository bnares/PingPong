//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



int velocity = -1;
int iloscOdbic =0;
AnsiString text ="";
int zwyciestwaLewego=0;
int zwyciestwaPrawego =0;
AnsiString wynik = "";
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

    //przegrana lewy

    if((Image3 ->Left<= Image1 ->Left-30))

    {
     zwyciestwaPrawego ++;
     Timer1 -> Enabled =false;
     Button1 ->Visible = true;
     Button2 ->Visible = true;
     Label1 -> Visible = true;
     Label2 -> Caption = "Punkt dla Gracza Prawego >>";
     Label2 -> Visible = true;
     wynik = IntToStr(zwyciestwaLewego)+" : "+IntToStr(zwyciestwaPrawego);
     Label3 ->Caption = wynik;
     Label3 ->Visible = true;

    }

    //przegrana prawy

    if(Image3 -> Left  >= Image2->Left +Image2->Width-10)
    {
     zwyciestwaLewego ++;
     Timer1 -> Enabled =false;
     Button1 ->Visible = true;
     Button2 ->Visible =true;
     Label1 -> Visible = true;
     Label2 -> Caption = "<<Punkt dla Gracza Lewego";
     Label2 -> Visible = true;
     wynik = IntToStr(zwyciestwaLewego)+" : "+IntToStr(zwyciestwaPrawego);
     Label3 ->Caption = wynik;
     Label3 ->Visible = true;


    }

    if((Image3 -> Top > Image1 -> Top) && (Image3 -> Top + Image3 -> Height < Image1 -> Top +Image1 -> Height) &&
        (Image1 -> Left + Image1 -> Width  >= Image3 -> Left))
        {
          velocity = -velocity;
          iloscOdbic ++;
          x = -x + velocity;
          y = -y;
          text = IntToStr(iloscOdbic);
          Label1 -> Caption = "Liczba odbic: "+text;

        }
    if((Image3 -> Top > Image2 -> Top) &&(Image3 -> Top + Image3 ->Height < Image2 -> Top +Image2->Height) &&
    (Image3 -> Left + Image3 -> Width >= Image2 -> Left))
    {
     iloscOdbic ++;
     velocity = -velocity;
     x = -x;
     y = -y + velocity;
     text = IntToStr(iloscOdbic);
     Label1 -> Caption = "Liczba odbic: "+text;

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
      Image3 ->Left =448;
      Image3 ->Top = 240;
      Timer1 ->Enabled =true;
      Button1 ->Visible = false;
      Button2 -> Visible =false;
      x = -5;
      y =-5;
      iloscOdbic =0;
      Label1 -> Visible = false;
      Label2 -> Visible = false;
      Label3 -> Visible = false;
      zwyciestwaLewego =0;
      zwyciestwaPrawego =0;
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

    if(Key == 0x41)
    {
     lewyGora -> Enabled = true;
    }

    if(Key == 0x5A)
    {
     lewyDol -> Enabled =true;
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


    if(Key == 0x41)
    {
     lewyGora -> Enabled = false;
    }

    if(Key == 0x5A)
    {
     lewyDol -> Enabled =false;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewyDolTimer(TObject *Sender)
{
  if(Image1 -> Top + Image1 -> Height <= Shape1 ->Height-3)
  {
      Image1 -> Top +=10;
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewyGoraTimer(TObject *Sender)
{
  if(Image1 ->Top >= 3)
  {
  Image1 ->Top-=10;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
      Image3 ->Left =448;
      Image3 ->Top = 240;
      Timer1 ->Enabled =true;
      Button1 ->Visible = false;
      Button2 ->Visible =false;
      x = -5;
      y =-5;
      iloscOdbic =0;
      Label1 -> Visible = false;
      Label2 -> Visible = false;
      Label3 -> Visible = false;
      //text ="0";
      Label1 -> Caption = "Liczba odbic: 0";


}
//---------------------------------------------------------------------------

