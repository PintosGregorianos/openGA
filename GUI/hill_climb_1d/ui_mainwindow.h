/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *edPopSize;
    QLabel *label;
    QLineEdit *edDNASize;
    QLabel *label_2;
    QLineEdit *edCrossProb;
    QLineEdit *edMutProb;
    QLineEdit *edElitimsRatio;
    QLineEdit *edCrossScale;
    QLineEdit *edMutScale;
    QLineEdit *edElitimsScale;
    QComboBox *cbCromType;
    QComboBox *cbCrossType;
    QPushButton *btStart;
    QPushButton *btStop;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QCustomPlot *cpSpace;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(629, 451);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 610, 170));
        edPopSize = new QLineEdit(groupBox);
        edPopSize->setObjectName(QStringLiteral("edPopSize"));
        edPopSize->setGeometry(QRect(10, 40, 140, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 76, 16));
        edDNASize = new QLineEdit(groupBox);
        edDNASize->setObjectName(QStringLiteral("edDNASize"));
        edDNASize->setGeometry(QRect(160, 40, 140, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 20, 47, 16));
        edCrossProb = new QLineEdit(groupBox);
        edCrossProb->setObjectName(QStringLiteral("edCrossProb"));
        edCrossProb->setGeometry(QRect(10, 90, 140, 20));
        edMutProb = new QLineEdit(groupBox);
        edMutProb->setObjectName(QStringLiteral("edMutProb"));
        edMutProb->setGeometry(QRect(160, 90, 140, 20));
        edElitimsRatio = new QLineEdit(groupBox);
        edElitimsRatio->setObjectName(QStringLiteral("edElitimsRatio"));
        edElitimsRatio->setGeometry(QRect(310, 90, 140, 20));
        edCrossScale = new QLineEdit(groupBox);
        edCrossScale->setObjectName(QStringLiteral("edCrossScale"));
        edCrossScale->setGeometry(QRect(10, 140, 140, 20));
        edMutScale = new QLineEdit(groupBox);
        edMutScale->setObjectName(QStringLiteral("edMutScale"));
        edMutScale->setGeometry(QRect(160, 140, 140, 20));
        edElitimsScale = new QLineEdit(groupBox);
        edElitimsScale->setObjectName(QStringLiteral("edElitimsScale"));
        edElitimsScale->setGeometry(QRect(310, 140, 140, 20));
        cbCromType = new QComboBox(groupBox);
        cbCromType->setObjectName(QStringLiteral("cbCromType"));
        cbCromType->setGeometry(QRect(310, 40, 140, 20));
        cbCrossType = new QComboBox(groupBox);
        cbCrossType->setObjectName(QStringLiteral("cbCrossType"));
        cbCrossType->setGeometry(QRect(460, 40, 140, 20));
        btStart = new QPushButton(groupBox);
        btStart->setObjectName(QStringLiteral("btStart"));
        btStart->setGeometry(QRect(460, 90, 140, 23));
        btStart->setMinimumSize(QSize(0, 0));
        btStop = new QPushButton(groupBox);
        btStop->setObjectName(QStringLiteral("btStop"));
        btStop->setGeometry(QRect(460, 140, 140, 23));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 20, 93, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 20, 79, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 70, 106, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 120, 121, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(160, 120, 121, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(310, 120, 111, 16));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(160, 70, 99, 16));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(310, 70, 61, 16));
        cpSpace = new QCustomPlot(centralWidget);
        cpSpace->setObjectName(QStringLiteral("cpSpace"));
        cpSpace->setGeometry(QRect(10, 190, 611, 251));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 629, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Genetic Algorithm Configuration", 0));
        label->setText(QApplication::translate("MainWindow", "Population Size:", 0));
        label_2->setText(QApplication::translate("MainWindow", "DNA Size:", 0));
        cbCromType->clear();
        cbCromType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Byte", 0)
         << QApplication::translate("MainWindow", "Signed Int", 0)
         << QApplication::translate("MainWindow", "Unsigned Int", 0)
         << QApplication::translate("MainWindow", "Float", 0)
         << QApplication::translate("MainWindow", "Double", 0)
        );
        cbCrossType->clear();
        cbCrossType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "One Cut", 0)
         << QApplication::translate("MainWindow", "Two Cut", 0)
         << QApplication::translate("MainWindow", "Cut Splice", 0)
        );
        btStart->setText(QApplication::translate("MainWindow", "Start", 0));
        btStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        label_3->setText(QApplication::translate("MainWindow", "Chromossome Size:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Crossover Type:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Crossover Probability:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Crossover Scale Factor:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Mutation Scale Factor:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Elitism Scale Factor:", 0));
        label_9->setText(QApplication::translate("MainWindow", "Mutation Probability:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Elitism Ratio:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
