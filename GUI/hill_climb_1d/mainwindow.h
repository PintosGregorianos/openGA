#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//---------------------------------------------------------------------------

#include <QMainWindow>
#include <windows.h>
#include <stdlib.h>
#include "hill_climb_1d.h"
#include "qcustomplot.h"
#include "openga_wrapper.h"
#include "polySpace.hpp"

//---------------------------------------------------------------------------

#define DEFAULT_FILE_NAME           "default.dat"
//const wchar_t DEFAULT_FILE_NAME[]=L"default.dat";

#define SPACE_DIM                   1
#define SPACE_SIZE                  2048
#define SPACE_ORDER                 16

//---------------------------------------------------------------------------

namespace Ui {
class MainWindow;
}

//---------------------------------------------------------------------------

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_edPopSize_textChanged(const QString &arg1);

    void on_edDNASize_textChanged(const QString &arg1);

    void on_cbCromType_currentIndexChanged(int index);

    void on_cbCrossType_currentIndexChanged(int index);

    void on_edCrossProb_textChanged(const QString &arg1);

    void on_edMutProb_textChanged(const QString &arg1);

    void on_edElitimsRatio_textChanged(const QString &arg1);

    void on_edCrossScale_textChanged(const QString &arg1);

    void on_edMutScale_textChanged(const QString &arg1);

    void on_edElitimsScale_textChanged(const QString &arg1);

    void on_btStart_clicked();

    void on_btStop_clicked();

private:
    Ui::MainWindow *ui;

    QCustomPlot *spacePlot;
    QCustomPlot *fitnessPlot;

    openga_wrapper openGA;

    polySpace *space;

    float *space_y;

    void initialize(void);
    void updateUI(void);

    float evaluateFitness(const dna &the_dna);
    void iterateGA(void);

    ga_config loadFile(char *filename);
    void saveFile(char *filename, ga_config config);
};

//---------------------------------------------------------------------------

#endif // MAINWINDOW_H
