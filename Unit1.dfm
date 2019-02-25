object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 693
  ClientWidth = 1181
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 1175
    Top = 73
    Width = 6
    Height = 620
    Align = alRight
    Font.Charset = TURKISH_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object Chart1: TChart
    Left = 0
    Top = 73
    Width = 1175
    Height = 620
    Legend.Visible = False
    PrintProportional = False
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    BottomAxis.Increment = 0.100000000000000000
    View3D = False
    Align = alClient
    TabOrder = 1
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      13
      15
      14
      17)
    ColorPaletteIndex = 13
    object Series1: TPointSeries
      Depth = 0
      SeriesColor = clRed
      ClickableLine = False
      Pointer.HorizSize = 2
      Pointer.InflateMargins = True
      Pointer.Pen.Color = clRed
      Pointer.Style = psDiagCross
      Pointer.VertSize = 2
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      Data = {
        00190000000000000000A48A4000000000002087400000000000308640000000
        0000AC874000000000004C884000000000004486400000000000C48840000000
        00002C8A4000000000007488400000000000B0884000000000000C8740000000
        0000EC88400000000000E4864000000000002488400000000000908A40000000
        0000B08D400000000000BC8B400000000000408A400000000000908A40000000
        00004C8D400000000000908F400000000000248D400000000000A08E40000000
        0000C48D400000000000F88B40}
      Detail = {0000000000}
    end
    object Series2: TPointSeries
      ClickableLine = False
      Pointer.HorizSize = 2
      Pointer.InflateMargins = True
      Pointer.Style = psDiagCross
      Pointer.VertSize = 2
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      Data = {
        00190000000000000000A48D400000000000688D4000000000008C8D40000000
        0000388D4000000000005E8E400000000000668F4000000000003A9040000000
        0000F68F400000000000D28F4000000000003C8F400000000000548F40000000
        00004E8F400000000000C48E400000000000848F400000000000FC8F40000000
        000046904000000000002E90400000000000A090400000000000F79040000000
        000027914000000000004B91400000000000D291400000000000A59140000000
        0000EA91400000000000C09140}
      Detail = {0000000000}
    end
    object Series3: TPointSeries
      ColorEachPoint = True
      Marks.Frame.Visible = False
      Marks.Transparent = True
      SeriesColor = 8454016
      ClickableLine = False
      Pointer.HorizSize = 2
      Pointer.InflateMargins = True
      Pointer.Pen.Color = clRed
      Pointer.Style = psDiagCross
      Pointer.VertSize = 2
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1181
    Height = 73
    Align = alTop
    TabOrder = 2
    object Label1: TLabel
      Left = 113
      Top = 29
      Width = 49
      Height = 13
      Caption = 'Iteration :'
    end
    object Label2: TLabel
      Left = 458
      Top = 29
      Width = 88
      Height = 13
      Caption = 'Function Number :'
    end
    object Button1: TButton
      Left = 32
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Start'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Txtiteration: TEdit
      Left = 168
      Top = 26
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '500000'
    end
    object Button2: TButton
      Left = 1279
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Button2'
      TabOrder = 2
      OnClick = Button2Click
    end
    object TxtFunction: TEdit
      Left = 552
      Top = 26
      Width = 57
      Height = 21
      TabOrder = 3
      Text = '3'
    end
  end
end
