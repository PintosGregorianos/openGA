object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 433
  ClientWidth = 729
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
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
    end
    object edCrossProb: TLabeledEdit
      Left = 16
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 106
      EditLabel.Height = 13
      EditLabel.Caption = 'Crossover Probability:'
      TabOrder = 2
    end
    object edElitimsRatio: TLabeledEdit
      Left = 270
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 61
      EditLabel.Height = 13
      EditLabel.Caption = 'Elitism Ratio:'
      TabOrder = 3
    end
    object edMutProb: TLabeledEdit
      Left = 143
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 99
      EditLabel.Height = 13
      EditLabel.Caption = 'Mutation Probability:'
      TabOrder = 4
    end
    object edCrossScale: TLabeledEdit
      Left = 16
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 115
      EditLabel.Height = 13
      EditLabel.Caption = 'Crossover Scale Factor:'
      TabOrder = 5
    end
    object edMutScale: TLabeledEdit
      Left = 143
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 108
      EditLabel.Height = 13
      EditLabel.Caption = 'Mutation Scale Factor:'
      TabOrder = 6
    end
    object edElitimsScale: TLabeledEdit
      Left = 270
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 95
      EditLabel.Height = 13
      EditLabel.Caption = 'Elitism Scale Factor:'
      TabOrder = 7
    end
    object cbCrossType: TComboBox
      Left = 397
      Top = 40
      Width = 121
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 8
      Text = 'One Cut'
      Items.Strings = (
        'One Cut'
        'Two Cut'
        'Cut Splice')
    end
    object ComboBox1: TComboBox
      Left = 270
      Top = 40
      Width = 121
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 9
      Text = 'Byte'
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
