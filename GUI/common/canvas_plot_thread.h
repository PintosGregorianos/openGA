//---------------------------------------------------------------------------

#ifndef canvas_plot_threadH
#define canvas_plot_threadH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <vector>

//---------------------------------------------------------------------------

#define PLOT_MARGIN               3
#define PLOT_DEF_BACKGROUND       clBlack
#define PLOT_DEF_GRID_COLOR       clGray
#define PLOT_DEF_GRID             50
#define PLOT_DEF_MAX              32767
#define PLOT_DEF_MIN              -32768

//---------------------------------------------------------------------------

struct signal_t{
   std::vector<int> data;
   int n_data;
   TColor color;
   int min;
   int max;
   int x;
   float scale;
};

struct plot_t{
   TCanvas *canvas;
   int c_width;
   int c_height;
   int d_width;
   int d_height;
   TColor background;
   std::vector<signal_t> signals;
   int n_signals;
   float scale;
};

//---------------------------------------------------------------------------

class canvas_plot_thread : public TThread
{
private:

   std::vector<plot_t> plot;
   int n_plots;

   //int x;

   int sample;
   int last_sample;

   //sync
   TColor color_s;
   TPenStyle style_s;
   int x1_s, x2_s;
   int y1_s, y2_s;
   int p_index_s;
   int s_index_s;

   void setupPlot(int plot_index);

   void plotSample(int plot_index, int sig_index, int n);

   void refreshSignal(int plot_index, int sig_index);

   int adjustSampleRange(int plot_index, int sig_index, int sample, float scale);
   int adjustRange(int x, int in_min, int in_max, int out_min, int out_max, float scale);

   void plotCanvas(int plot_index, int sig_index, TColor color);
   void clearCanvasSignal(int plot_index, int sig_index);
   void setCanvasBackground(int plot_index);
   void drawCanvasGrid(int plot_index);

   void setPenColor(int plot_index, TColor color);
   void setPenStyle(int plot_index, TPenStyle style);
   void setBrushColor(int plot_index, TColor color);
   void moveTo(int plot_index, int x, int y);
   void lineTo(int plot_index, int x, int y);
   void drawRectangle(int plot_index, int x1, int y1, int x2, int y2);

   void __fastcall setPenColorS(void);
   void __fastcall setPenStyleS(void);
   void __fastcall setBrushColorS(void);
   void __fastcall moveToS(void);
   void __fastcall lineToS(void);
   void __fastcall drawRectangleS(void);

   void __fastcall Execute();
public:

   int period;

   void addCanvas(TCanvas *canvas, int height, int width);
   void addSignal(int plot_index, TColor color);
   void addData(int plot_index, int sig_index, int data);
   void addData(int plot_index, int sig_index, int *data, int size);

   void setSignalColor(int plot_index, int sig_index, TColor color);

   void removeSignal(int plot_index, int sig_index);

   void clearPlot(int plot_index);
   void clearSignal(int plot_index, int sig_index);

   void resizePlot(int plot_index, int height, int width);

   __fastcall canvas_plot_thread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
