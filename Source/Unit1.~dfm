object Form1: TForm1
  Left = 618
  Top = 443
  Width = 513
  Height = 200
  Caption = 'FEX.NET Uploader'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = OnCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 32
    Top = 80
    Width = 113
    Height = 25
    Caption = 'Upload'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 112
    Width = 113
    Height = 25
    Caption = 'View Log'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 192
    Top = 80
    Width = 113
    Height = 25
    Caption = 'Open Link'
    Enabled = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Memo1: TMemo
    Left = 32
    Top = 24
    Width = 433
    Height = 25
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
  end
  object Button4: TButton
    Left = 192
    Top = 112
    Width = 113
    Height = 25
    Caption = 'Clear Log'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 352
    Top = 80
    Width = 113
    Height = 25
    Caption = 'Copy Link'
    Enabled = False
    TabOrder = 5
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 352
    Top = 112
    Width = 113
    Height = 25
    Caption = 'Exit'
    TabOrder = 6
    OnClick = Button6Click
  end
  object ProgressBar1: TProgressBar
    Left = 32
    Top = 56
    Width = 433
    Height = 17
    Min = 0
    Max = 100
    TabOrder = 7
  end
  object IdHTTP1: TIdHTTP
    OnWork = IdHTTP1Work
    OnWorkBegin = IdHTTP1WorkBegin
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.CharSet = 'utf-8'
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = []
    Left = 472
    Top = 24
  end
  object IdSSLIOHandlerSocketOpenSSL1: TIdSSLIOHandlerSocketOpenSSL
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 472
    Top = 64
  end
  object OpenDialog1: TOpenDialog
    Left = 472
    Top = 104
  end
end
