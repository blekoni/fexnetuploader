//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstdio>
#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <ctime>
#pragma hdrstop
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>
#include <IdURI.hpp>
#include <IdMultipartFormData.hpp>
#include "Unit2.h"


#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdIOHandler"
#pragma link "IdIOHandlerSocket"
#pragma link "IdIOHandlerStack"
#pragma link "IdSSL"
#pragma link "IdIOHandler"
#pragma link "IdIOHandlerSocket"
#pragma link "IdIOHandlerStack"
#pragma link "IdSSL"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

int f=0;


char* findtoken(char* str)
{
       char* token= new char[13];
        int i=0;
        while(str[i]!='\0')
        {
                if(str[i]=='t')
                    if(str[i+1]=='o')
                    {
                        i=i+8;
                        for(int j=0;j<12;j++)
                        {

                            token[j]= str[i];
                            i++;
                        }
                        token[12]='\0';
                        return token;
                    }
            i++;
        }
        return token;
}



char* findlink(char str[])
{
       char* link= new char[34];
        int i=0;
        int j=0;
        while(str[i]!='\0')
        {
                if(str[i]=='h')
                    if(str[i+1]=='t')
                    {
                        do
                        {
                            link[j]=str[i];
                            j++;
                            i++;
                        }while (str[i]!='"');
                        link[j]='/';
                        link[j+1]='\0';
                        return link;
                    }
            i++;
        }
        return link;
}


void print_log(String FileName){
        ofstream log;

        String patch=ExtractFilePath(Application->ExeName).c_str();
        patch=patch+"log.txt";
      //  Form1->Memo1->Text=patch;
        log.open(patch.c_str(), std::ios::app);
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        log << asctime(timeinfo)<<endl;
        log << FileName.c_str()<<endl;
        log << Form1->Memo1->Lines->Strings[0].c_str()<<endl;
        log << "===================================================="<<endl<<endl;
        log.close();
}
void create_folder(){
f=1;
try
{

        AnsiString text;
        AnsiString text2;
        Form1->IdHTTP1->Request->UserAgent="Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36 Cent/1.4.0.2";
        Form1->IdHTTP1->IOHandler = Form1->IdSSLIOHandlerSocketOpenSSL1;
        Form1->IdSSLIOHandlerSocketOpenSSL1->SSLOptions->Method=sslvTLSv1_2;
        Form1->IdHTTP1->Request->ContentEncoding='8';
        Form1->IdHTTP1->Request->CharSet="utf-8";
        text=Form1->IdHTTP1->Get("https://fex.net/j_object_create");
        Form1->IdHTTP1->Request->CharSet="utf-8";
        
        char* response = new char[text.Length() + 1];
        strcpy(response, text.c_str());
        response[text.Length()] = '\0';

        Form1->token= new char[13];
        strcpy(Form1->token,findtoken(response));
        delete[] response;

        text2=Form1->IdHTTP1->Get("https://fex.net/j_object_view/" + AnsiString(Form1->token));
        char* response2 = new char[text2.Length() + 1];
        strcpy(response2, text2.c_str());
        response2[text2.Length()] = '\0';

        Form1->upload_link= new char[34];
        strcpy(Form1->upload_link,findlink(response2));
        delete[] response2;
  }
  catch(EIdHTTPProtocolException &E)
  {
    // ....
  }
  catch(EIdSocketError &E)
  {
    ShowMessage(E.LastError);
  }
}

void upload_newfolder()
{
f=1;


try
{
        TMyThread *Thr;
        Thr = new TMyThread(true);
        Form1->Button1->Enabled=false;
        Thr->FreeOnTerminate = true;
        Thr->Suspended = false;

  }
  catch(EIdHTTPProtocolException &E)
  {
    // ....
  }
  catch(EIdSocketError &E)
  {
    ShowMessage(E.LastError);
  }
}


void upload_oldfolder()
{
try
{
        AnsiString text;
        AnsiString text2;

        TMyThread *Thr;
        Thr = new TMyThread(true);
        Thr->param=false;
        Form1->Button1->Enabled=false;
        Thr->FreeOnTerminate = true;
        Thr->Suspended = false;
  }
  catch(EIdHTTPProtocolException &E)
  {
    // ....
  }
  catch(EIdSocketError &E)
  {
    ShowMessage(E.LastError);
  }
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{

        String patch=ExtractFilePath(Application->ExeName).c_str();
        patch=patch+"log.txt";
        if(FileExists(patch))
                ShellExecute(Handle,"open","notepad", ("\"" + patch +  "\"").c_str(), NULL,SW_NORMAL);
        else
        {
                ofstream ofs(patch.c_str()); 
                ofs.close();
                ShellExecute(Handle,"open","notepad", ("\"" + patch +  "\"").c_str(), NULL,SW_NORMAL);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        AnsiString doc = AnsiString(Memo1->Lines->Strings[0]);
        ShellExecute(NULL,"open",doc.c_str(),NULL,NULL,SW_RESTORE);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ProgressBar1->Position = 0;
        if(!f)
                create_folder();
        upload_oldfolder();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{

        ofstream log;
        String patch=ExtractFilePath(Application->ExeName).c_str();
        patch=patch+"log.txt";
        log.open(patch.c_str(), std::ios::out);
        log.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Memo1->SelStart=0;
        Memo1->SelLength = 29;
        if(Memo1->SelLength > 0) Memo1->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        Close();        
}


//---------------------------------------------------------------------------
void __fastcall TForm1::OnCreate(TObject *Sender)
{
       Memo1->Lines->Clear();

       Sleep(1);
       WIN32_FIND_DATA data;
       FindFirstFileA(ParamStr(1).c_str(), &data);
       if(data.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
       if(ParamCount()==1){
                create_folder();
                TMyThread *Thr;
                Thr = new TMyThread(true);
                Thr->param=true;
                Form1->Button1->Enabled=false;
                Thr->FreeOnTerminate = true;
                Thr->Suspended = false;
       }

}
void __fastcall TForm1::IdHTTP1WorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax)

{
  if(AWorkMode==wmWrite)
    ProgressBar1->Max = AWorkCountMax;
}

void __fastcall TForm1::IdHTTP1Work(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)
{

  if(AWorkMode==wmWrite)
    ProgressBar1->Position = AWorkCount;
}



