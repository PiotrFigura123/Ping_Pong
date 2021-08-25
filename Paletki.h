//---------------------------------------------------------------------------

#ifndef PaletkiH
#define PaletkiH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TTimer *Timer_pilka;
        TImage *pilka;
        TTimer *left1;
        TImage *pal1;
        TImage *pal2;
        TTimer *right1;
        TTimer *left2;
        TTimer *right2;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall Timer_pilkaTimer(TObject *Sender);
        void __fastcall left1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall right1Timer(TObject *Sender);
        void __fastcall left2Timer(TObject *Sender);
        void __fastcall right2Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
