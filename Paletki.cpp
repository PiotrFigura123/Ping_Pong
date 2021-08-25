//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Paletki.h"
int x=8;
int y=8;
int pkt_player1=0;
int pkt_player2=0;

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
 }
 else if(pilka->Top>=pal1->Top+pal1->Height)
  {
  pkt_player2++;
 Timer_pilka->Enabled=false;
 pilka->Visible=false;
 Label2->Caption = pkt_player2;
 }
 else if( pilka->Top+pilka->Height>pal1->Top)
        {
                if(pilka->Left > pal1->Left-pilka->Width/2 && pilka->Left < pal1->Left+40){y=-y;x=x*1.1;}
                if(pilka->Left >= pal1->Left+40 && pilka->Left < pal1->Left+80)           {if (y<15)y=-y*1.2;}
                if(pilka->Left >= pal1->Left+90 && pilka->Left < pal1->Left+pal1->Width)  {y=-y;x=x*1.1;}
        }
  else if( pilka->Top<pal2->Top+pal2->Height)
        {
                if(pilka->Left > pal2->Left-pilka->Width/2 && pilka->Left < pal2->Left+40){y=-y;x=x*1.1;}
                if(pilka->Left >= pal2->Left+40 && pilka->Left < pal2->Left+80)           {if (y<15)y=-y*1.2;}
                if(pilka->Left >= pal2->Left+90 && pilka->Left < pal2->Left+pal1->Width)  {y=-y;x=x*1.1;}
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
