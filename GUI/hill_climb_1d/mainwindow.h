#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//---------------------------------------------------------------------------

#include <QMainWindow>
#include "hill_climb_1d.h"
#include "qcustomplot.h"
#include "openga_wrapper.h"
#include "polySpace.hpp"

//---------------------------------------------------------------------------

#define DEFAULT_FILE_NAME           "default.dat"
//const wchar_t DEFAULT_FILE_NAME[]=L"default.dat";

#define SPACE_DIM                   1
#define SPACE_SIZE                  256
#define SPACE_ORDER                 6

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

private:
    Ui::MainWindow *ui;

    QCustomPlot *spacePlot;

    openga_wrapper openGA;

    polySpace *space;

    const float *space_y;

    void initialize(void);
    void updateUI(void);

    //static function pointer connections
    //C++ callbaks are awkward
    static float staticFitnessCallback(void *p, const dna &the_dna){
       // Get back into the class by treating p as the "this" pointer.
       return ((MainWindow *)p)->evaluateFitness(the_dna);
    }

    static void staticIterationCallback(void *p){
       // Get back into the class by treating p as the "this" pointer.
       ((MainWindow *)p)->iterateGA();
    }

    float evaluateFitness(const dna &the_dna);
    void iterateGA(void);

    ga_config loadFile(char *filename);
    void saveFile(char *filename, ga_config config);
};

//---------------------------------------------------------------------------

#endif // MAINWINDOW_H
