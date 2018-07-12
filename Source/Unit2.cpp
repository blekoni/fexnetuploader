//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream.h>
#include "Unit2.h"
#include "Unit1.h"
#pragma package(smart_init)
using namespace std;
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TMyThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

void print_log(String FileName){
        ofstream log;

        String patch=ExtractFilePath(Application->ExeName).c_str();
        patch=patch+"log.txt";
        log.open(patch.c_str(), std::ios::app);
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        log << asctime(timeinfo)<<endl;
        log << FileName.c_str()<<endl;
        log << Form1->Memo1->Lines->Strings[0].c_str()<<endl;
        log << "===================================================="<<endl<<endl;
        log.close();
}

__fastcall TMyThread::TMyThread(bool CreateSuspended)
        : TThread(CreateSuspended)
{



}
//---------------------------------------------------------------------------
void __fastcall TMyThread::Execute()
{
        AnsiString FileName1= ParamStr(1);
        char* FilePath = new char[FileName1.Length() + 1];
        strcpy(FilePath, FileName1.c_str());
        if(param)
        {
              Form1->Memo1->Text=(("http://fex.net/"+AnsiString(Form1->token)));
              String FileName= ParamStr(1);
              TIdMultiPartFormDataStream *MultiData = new TIdMultiPartFormDataStream;
              TIdFormDataField* fdf=MultiData->AddFile("file", FileName);
              fdf->HeaderCharSet="utf-8";
              fdf->HeaderEncoding='8';
              AnsiString response3;
              response3 = Form1->IdHTTP1->Post(AnsiString(Form1->upload_link) + AnsiString(Form1->token), MultiData);
              print_log(FileName);
              Form1->Button3->Enabled=true;
              Form1->Button5->Enabled=true;
              MultiData->Free();
        }
        else
        if(Form1->OpenDialog1->Execute() )
        {

                Form1->Memo1->Text=(("http://fex.net/"+AnsiString(Form1->token)));
                String FileName= Form1->OpenDialog1->FileName;
                TIdMultiPartFormDataStream *MultiData = new TIdMultiPartFormDataStream;
                TIdFormDataField* fdf=MultiData->AddFile("file", FileName);
                fdf->HeaderCharSet="utf-8";
                fdf->HeaderEncoding='8';
                AnsiString response3;
                response3 = Form1->IdHTTP1->Post(AnsiString(Form1->upload_link) + AnsiString(Form1->token), MultiData);
                print_log(FileName);
                Form1->Button3->Enabled=true;
                Form1->Button5->Enabled=true;
                MultiData->Free();
        }
        Form1->Button1->Enabled=true;
}


//---------------------------------------------------------------------------
