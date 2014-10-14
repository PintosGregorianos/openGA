object fmMain: TfmMain
  Left = 0
  Top = 0
  Caption = 'openGA Hill Climb 1D'
  ClientHeight = 433
  ClientWidth = 547
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object imPlot: TImage
    Left = 8
    Top = 167
    Width = 529
    Height = 258
  end
  object gbGAConfig: TGroupBox
    Left = 8
    Top = 8
    Width = 529
    Height = 153
    Caption = 'Genetic Algorithm Configuration'
    TabOrder = 0
    object lbCrossType: TLabel
      Left = 397
      Top = 24
      Width = 80
      Height = 13
      Caption = 'Crossover Type:'
    end
    object Label1: TLabel
      Left = 270
      Top = 24
      Width = 92
      Height = 13
      Caption = 'Cromossome Type:'
    end
    object edPopSize: TLabeledEdit
      Left = 16
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 76
      EditLabel.Height = 13
      EditLabel.Caption = 'Population Size:'
      TabOrder = 0
      OnChange = edPopSizeChange
    end
    object edDNASize: TLabeledEdit
      Left = 143
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'DNA Size:'
      TabOrder = 1
      OnChange = edDNASizeChange
    end
    object edCrossProb: TLabeledEdit
      Left = 16
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 106
      EditLabel.Height = 13
      EditLabel.Caption = 'Crossover Probability:'
      TabOrder = 4
      OnChange = edCrossProbChange
    end
    object edElitimsRatio: TLabeledEdit
      Left = 270
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 61
      EditLabel.Height = 13
      EditLabel.Caption = 'Elitism Ratio:'
      TabOrder = 5
      OnChange = edElitimsRatioChange
    end
    object edMutProb: TLabeledEdit
      Left = 143
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 99
      EditLabel.Height = 13
      EditLabel.Caption = 'Mutation Probability:'
      TabOrder = 6
      OnChange = edMutProbChange
    end
    object edCrossScale: TLabeledEdit
      Left = 16
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 115
      EditLabel.Height = 13
      EditLabel.Caption = 'Crossover Scale Factor:'
      TabOrder = 7
      OnChange = edCrossScaleChange
    end
    object edMutScale: TLabeledEdit
      Left = 143
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 108
      EditLabel.Height = 13
      EditLabel.Caption = 'Mutation Scale Factor:'
      TabOrder = 8
      OnChange = edMutScaleChange
    end
    object edElitimsScale: TLabeledEdit
      Left = 270
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 95
      EditLabel.Height = 13
      EditLabel.Caption = 'Elitism Scale Factor:'
      TabOrder = 9
      OnChange = edElitimsScaleChange
    end
    object cbCrossType: TComboBox
      Left = 397
      Top = 40
      Width = 121
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 3
      Text = 'One Cut'
      OnChange = cbCrossTypeChange
      Items.Strings = (
        'One Cut'
        'Two Cut'
        'Cut Splice')
    end
    object cbCromType: TComboBox
      Left = 270
      Top = 40
      Width = 121
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 2
      Text = 'Byte'
      OnChange = cbCromTypeChange
      Items.Strings = (
        'Byte'
        'Signed Int'
        'Usigned Int'
        'Float'
        'Double')
    end
    object Button1: TButton
      Left = 397
      Top = 78
      Width = 121
      Height = 25
      Caption = 'Start'
      TabOrder = 10
    end
    object Button2: TButton
      Left = 397
      Top = 118
      Width = 121
      Height = 25
      Caption = 'Stop'
      TabOrder = 11
    end
  end
end
