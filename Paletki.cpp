//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Paletki.h"
int x=3;
int y=3;
int pkt_player1=0;
int pkt_player2=0;
int kierunek=1;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
Label1->Caption = pkt_player1;
Label2->Caption = pkt_player2;
 pilka->Left+=x;
 pilka->Top+=y;
 if(pilka->Left-5 <=tlo->Left)x=-x;
 if(pilka->Left+pilka->Width+5 >=tlo->Left+tlo->Width) x=-x;

 if(pilka->Top <=pal2->Top-pal2->Height)
  {
  pkt_player1++;
   Timer_pilka->Enabled=false;
   pilka->Visible=false;
   Label1->Caption = pkt_player1;
   Label1->Visible=true;
   Label2->Visible=true;
   Label4->Visible=true;
   Label4->Caption = "Punkt!";
   Button1->Visible=true;
   Button2->Visible=true;
   kierunek=1;
   MediaPlayer2->Play();
 }
 else if(pilka->Top>=pal1->Top+pal1->Height)
  {
   pkt_player2++;
   Timer_pilka->Enabled=false;
   pilka->Visible=false;
   Label2->Caption = pkt_player2;
   Label1->Visible=true;
   Label2->Visible=true;
   Label3->Visible=true;
   Label3->Caption = "Punkt!";
   Button1->Visible=true;
   Button2->Visible=true;
   kierunek=-1;
   MediaPlayer2->Play();
 }
 else if( pilka->Top+pilka->Height>pal1->Top)
        {
                if(pilka->Left > pal1->Left-pilka->Width/2 && pilka->Left < pal1->Left+40){if(y>0)y=-y;x=x*1.1;}
                if(pilka->Left >= pal1->Left+40 && pilka->Left < pal1->Left+80)           {if(y>0)if (y<15)y=-y*1.2;}
                if(pilka->Left >= pal1->Left+90 && pilka->Left < pal1->Left+pal1->Width)  {if(y>0)y=-y;x=x*1.1;}
        }
  else if( pilka->Top<pal2->Top+pal2->Height)
        {
                if(pilka->Left > pal2->Left-pilka->Width/2 && pilka->Left < pal2->Left+40){if(y<0)y=-y;x=x*1.1;}
                if(pilka->Left >= pal2->Left+40 && pilka->Left < pal2->Left+80)           {if(y<0)if(y<15)y=-y*1.2;}
                if(pilka->Left >= pal2->Left+90 && pilka->Left < pal2->Left+pal1->Width)  {if(y<0)y=-y;x=x*1.1;}
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::left1Timer(TObject *Sender)
{
if(pal1->Left>3) pal1->Left-=10;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key==VK_LEFT) left1->Enabled=true;
if (Key==VK_RIGHT) right1->Enabled=true;
if (Key==0x41) left2->Enabled=true;
if (Key==0x53) right2->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key==VK_LEFT) left1->Enabled=false;
if (Key==VK_RIGHT) right1->Enabled=false;
if (Key==0x41) left2->Enabled=false;
if (Key==0x53) right2->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::right1Timer(TObject *Sender)
{
if(pal1->Left +pal1->Width< tlo->Width-3) pal1->Left+=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::left2Timer(TObject *Sender)
{
if(pal2->Left>3) pal2->Left-=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::right2Timer(TObject *Sender)
{
if(pal2->Left +pal2->Width< tlo->Width-3)pal2->Left+=10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
 pilka->Top=270;
 pilka->Left=220;
 x=-1*random(3);
 if(x<0) x=x-3;
 else x=x+3;
 y=kierunek*random(3);
 if(y<0) y=y-3;
 else y=y+3;
 pilka->Visible=true;
 Timer_pilka->Enabled=true;
 Label1->Visible=false;
 Label2->Visible=false;
 Label3->Visible=false;
 Label4->Visible=false;
Button1->Visible=false;
Button2->Visible=false;
MediaPlayer1->Play();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 pilka->Top=190;
 pilka->Left=130;
  x=-1*random(3);
 if(x<0) x=x-5;
 else x=x+5;
 y=kierunek*random(3);
 if(y<0) y=y-5;
 else y=y+5;
 pilka->Visible=true;
 Timer_pilka->Enabled=true;
Button1->Visible=false;
Button2->Visible=false;
pkt_player1=0;
pkt_player2=0;
Label1->Visible=false;
 Label2->Visible=false;
 Label3->Visible=false;
 Label4->Visible=false;
 Label2->Caption = pkt_player2;
  Label1->Caption = pkt_player1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
             MediaPlayer1->FileName= "snd/during game.wav";
             MediaPlayer2->FileName= "snd/skucha.wav";
             MediaPlayer3->FileName= "snd/start.wav";
             MediaPlayer1->Open();
             MediaPlayer3->Open();
             MediaPlayer2->Open();
            MediaPlayer1->Play();
            }
            //---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  MediaPlayer1->Close();
  MediaPlayer3->Close();
             MediaPlayer2->Close();
}
//---------------------------------------------------------------------------

