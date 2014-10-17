#include "mainwindow.h"
#include "ui_mainwindow.h"

//---------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   initialize();
}

//---------------------------------------------------------------------------

MainWindow::~MainWindow()
{
   saveFile((char*)DEFAULT_FILE_NAME, openGA.getGAConfig());
   delete ui;
}

//---------------------------------------------------------------------------

void MainWindow::initialize(void){
   seed_from_time();

   space=new polySpace((std::size_t)SPACE_DIM, (std::size_t)SPACE_SIZE, (std::size_t)SPACE_ORDER);
   spacePlot=ui->cpSpace;

   // create graph and assign data to it:
   spacePlot->addGraph();
   // give the axes some labels:
   spacePlot->xAxis->setLabel("x");
   spacePlot->yAxis->setLabel("y");
   // set axes ranges, so we see all data:
   spacePlot->xAxis->setRange(0, SPACE_SIZE);
   spacePlot->yAxis->setRange(-1, 1);
   spacePlot->replot();

   openGA.setGAConfig(loadFile((char*)DEFAULT_FILE_NAME));
   updateUI();
}

//---------------------------------------------------------------------------

void MainWindow::updateUI(void){
   cromossome_type_e cromo_type;
   crossover_type cross_type;

   ui->edPopSize->setText(QString::number(openGA.getPopulationSize()));
   ui->edDNASize->setText(QString::number(openGA.getDNASize()));

   cromo_type=openGA.getCromossomeType();
   switch (cromo_type){
      case cromossome_type_e::ct_byte: ui->cbCromType->setCurrentIndex(0); break;
      case cromossome_type_e::ct_signedInt: ui->cbCromType->setCurrentIndex(1); break;
      case cromossome_type_e::ct_unsignedInt: ui->cbCromType->setCurrentIndex(2); break;
      case cromossome_type_e::ct_float: ui->cbCromType->setCurrentIndex(3); break;
      case cromossome_type_e::ct_double: ui->cbCromType->setCurrentIndex(4); break;
   }

   cross_type=openGA.getCrossoverType();
   switch (cross_type){
      case crossover_type::onePoint: ui->cbCrossType->setCurrentIndex(0); break;
      case crossover_type::twoPoint: ui->cbCrossType->setCurrentIndex(1); break;
      case crossover_type::cutSplice: ui->cbCrossType->setCurrentIndex(2); break;
   }

   ui->edCrossProb->setText(QString::number(openGA.getCrossoverProbability()));
   ui->edMutProb->setText(QString::number(openGA.getMutationProbability()));
   ui->edElitimsRatio->setText(QString::number(openGA.getElitismRatio()));

   ui->edCrossScale->setText(QString::number(openGA.getCrossoverScaleFactor()));
   ui->edMutScale->setText(QString::number(openGA.getMutationScaleFactor()));
   ui->edElitimsScale->setText(QString::number(openGA.getElitismScaleFactor()));
}

//---------------------------------------------------------------------------

ga_config MainWindow::loadFile(char *filename){
   FILE *fpointer=NULL;
   union file_stream{
      ga_config file;
      char raw[sizeof(ga_config)];
   } data;

   fpointer=fopen(filename, "rb");
   fread(&data.raw, 1, sizeof(ga_config), fpointer);
   fclose(fpointer);

   return data.file;
}

//---------------------------------------------------------------------------

void MainWindow::saveFile(char *filename, ga_config config){
   FILE *fpointer=NULL;
   union file_stream{
      ga_config file;
      char raw[sizeof(ga_config)];
   } data;

   data.file=config;

   fpointer=fopen(filename, "wb");
   fwrite(&data.raw, 1, sizeof(ga_config), fpointer);
   fclose(fpointer);
}

//---------------------------------------------------------------------------

void MainWindow::on_edPopSize_textChanged(const QString &arg1)
{
   openGA.setPopulationSize(arg1.toInt());
}

//---------------------------------------------------------------------------

void MainWindow::on_edDNASize_textChanged(const QString &arg1)
{
   openGA.setDNASize(arg1.toInt());
}

//---------------------------------------------------------------------------

void MainWindow::on_cbCromType_currentIndexChanged(int index)
{
   cromossome_type_e type=cromossome_type_e::ct_byte;

   switch (index){
      case 0: type=cromossome_type_e::ct_byte; break;
      case 1: type=cromossome_type_e::ct_signedInt; break;
      case 2: type=cromossome_type_e::ct_unsignedInt; break;
      case 3: type=cromossome_type_e::ct_float; break;
      case 4: type=cromossome_type_e::ct_double; break;
   }

   openGA.setCromossomeType(type);
}

//---------------------------------------------------------------------------

void MainWindow::on_cbCrossType_currentIndexChanged(int index)
{
   crossover_type type=crossover_type::onePoint;

   switch (index){
      case 0: type=crossover_type::onePoint; break;
      case 1: type=crossover_type::twoPoint; break;
      case 2: type=crossover_type::cutSplice; break;;
   }

   openGA.setCrossoverType(type);
}

//---------------------------------------------------------------------------

void MainWindow::on_edCrossProb_textChanged(const QString &arg1)
{
   openGA.setCrossoverProbability(arg1.toFloat());
}

//---------------------------------------------------------------------------

void MainWindow::on_edMutProb_textChanged(const QString &arg1)
{
   openGA.setMutationProbability(arg1.toFloat());
}

//---------------------------------------------------------------------------

void MainWindow::on_edElitimsRatio_textChanged(const QString &arg1)
{
   openGA.setElitismRatio(arg1.toFloat());
}

//---------------------------------------------------------------------------

void MainWindow::on_edCrossScale_textChanged(const QString &arg1)
{
   openGA.setCrossoverScaleFactor(arg1.toFloat());
}

//---------------------------------------------------------------------------

void MainWindow::on_edMutScale_textChanged(const QString &arg1)
{
   openGA.setMutationScaleFactor(arg1.toFloat());
}

//---------------------------------------------------------------------------

void MainWindow::on_edElitimsScale_textChanged(const QString &arg1)
{
   openGA.setElitismScaleFactor(arg1.toFloat());
}

//---------------------------------------------------------------------------

void MainWindow::on_btStart_clicked()
{
   QVector<double> xq(SPACE_SIZE);
   QVector<double> yq(SPACE_SIZE);
   const float *y;
   float y_max=0;
   float y_min=0;
   int i;

   space->generate();
   y=space->getDimension(0);

   //MyQvector = QVector::fromStdVector( MyStedVector );

   for (i=0; i<SPACE_SIZE-1; i++)
   {
     xq[i]=i;
     yq[i]=y[i];
     y_max=std::max(y_max, y[i]);
     y_min=std::min(y_min, y[i]);
   }

   spacePlot->yAxis->setRange(y_min, y_max);
   spacePlot->graph(0)->setData(xq, yq);
   spacePlot->replot();
}

//---------------------------------------------------------------------------
