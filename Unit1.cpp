//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TForm1 *Form1;



int obstacleVelocity = -1;
int iloscOdbic =0;
AnsiString text ="";
int zwyciestwaLewego=0;
int zwyciestwaPrawego =0;
AnsiString wynik = "";
int x =-5;
int y = -5;


void lewyPrzegrywa();

void prawyPrzegrywa()
{
    zwyciestwaLewego ++;
     Form1 -> Timer1 -> Enabled =false;
     Form1 -> Button1 ->Visible = true;
     Form1 -> Button2 ->Visible =true;
     Form1 -> Label1 -> Visible = true;
     Form1 -> Label2 -> Caption = "<<Punkt dla Gracza Lewego";
     Form1 -> Label2 -> Visible = true;
     wynik = IntToStr(zwyciestwaLewego)+" : "+IntToStr(zwyciestwaPrawego);
     Form1 -> Label3 ->Caption = wynik;
     Form1 -> Label3 ->Visible = true;
     Form1 -> CGauge2 -> Progress = Form1 -> CGauge2 ->Progress -25;
     x = -5;
     y = -5;

}

void strataZycia()
{
  if(Form1 -> CGauge1 ->Progress ==0)
  {
        ShowMessage("Wygraly Prawe");
        Form1 -> Button2 -> Enabled = false;
  }

  if(Form1 -> CGauge2 -> Progress ==0)
  {
     ShowMessage("Wygraly Lewe");
     Form1 -> Button2 -> Enabled = false;
  }


}


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
     lewyPrzegrywa();
     strataZycia();

    }

    //przegrana prawy

    if(Image3 -> Left  >= Image2->Left +Image2->Width-10)
    {

     prawyPrzegrywa();
     strataZycia();
    }

    //odbija lewy
    
    if((Image3 -> Top < Image1 -> Top + Image1 ->Height) && (Image3 -> Top + Image3 -> Height > Image1 -> Top) &&
        (Image1 -> Left + Image1 -> Width+5  >= Image3 -> Left))
        {

          iloscOdbic ++;
          x = -x;
          y = -y;
          text = IntToStr(iloscOdbic);
          Label1 -> Caption = "Liczba odbic: "+text;
          if(iloscOdbic%5==0)
          {
           x = x+2;

          }

          if(x>20)
          {
           x =10;
           y =6;

          }

        }

    //odbija prawy

    if((Image3 -> Top < Image2 -> Top + Image2 -> Height) &&(Image3 -> Top + Image3 ->Height > Image2 -> Top) &&
    (Image3 -> Left + Image3 -> Width-5 >= Image2 -> Left))
    {
     iloscOdbic ++;

     x = -x;
     y = -y;
     text = IntToStr(iloscOdbic);
     Label1 -> Caption = "Liczba odbic: "+text;
     if(iloscOdbic%5==0)
     {
      x = x-1;

     }
     if(x>20)
     {
     x =10;
     y =6;

     }

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
      Button2 -> Enabled = true;
      x = -5;
      y =-5;
      iloscOdbic =0;
      Label1 -> Visible = false;
      Label2 -> Visible = false;
      Label3 -> Visible = false;
      zwyciestwaLewego =0;
      zwyciestwaPrawego =0;
      CGauge1 -> Progress =100;
      CGauge2 -> Progress =100;

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
      Label1 -> Caption = "Liczba odbic: 0";


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
    Button3 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Timer1 -> Enabled = true;
 Button3 -> Visible = false;
}
//---------------------------------------------------------------------------



void lewyPrzegrywa()
{
     zwyciestwaPrawego ++;
     Form1 -> Timer1 -> Enabled =false;
     Form1 -> Button1 ->Visible = true;
     Form1 -> Button2 ->Visible = true;
     Form1 -> Label1 -> Visible = true;
     Form1 -> Label2 -> Caption = "Punkt dla Gracza Prawego >>";
     Form1 -> Label2 -> Visible = true;
     wynik = IntToStr(zwyciestwaLewego)+" : "+IntToStr(zwyciestwaPrawego);
     Form1 -> Label3 ->Caption = wynik;
     Form1 -> Label3 ->Visible = true;
     Form1 -> CGauge1 -> Progress = Form1 -> CGauge1 ->Progress -25;
     x = -5;
     y = -5;

}




void __fastcall TForm1::FormCreate(TObject *Sender)
{
        ShowMessage("Witaj w grze!.");
}








//---------------------------------------------------------------------------

