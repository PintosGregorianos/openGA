//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "canvas_plot_thread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall signal_gen::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall canvas_plot_thread::canvas_plot_thread(bool CreateSuspended)
   : TThread(CreateSuspended)
{
   n_plots=0;
   period=20;
}
//---------------------------------------------------------------------------
void __fastcall canvas_plot_thread::Execute()
{
   while (!Terminated){
      Sleep(period);
   }
}

//---------------------------------------------------------------------------

void canvas_plot_thread::addCanvas(TCanvas *canvas, int height, int width){
   plot.resize(n_plots+1);
   plot[n_plots].canvas=canvas;
   plot[n_plots].c_height=height;
   plot[n_plots].c_width=width;

   plot[n_plots].n_signals=0;

   plot[n_plots].d_height=height-2*PLOT_MARGIN;
   plot[n_plots].d_width=width-2*PLOT_MARGIN;

   plot[n_plots].background=PLOT_DEF_BACKGROUND;

   plot[n_plots].scale=1;

   setupPlot(n_plots);

   n_plots++;
}

//---------------------------------------------------------------------------

void canvas_plot_thread::addSignal(int plot_index, TColor color){
   int n;

   n=plot[plot_index].n_signals;

   plot[plot_index].signals.resize(n+1);
   plot[plot_index].signals[n].color=color;
   plot[plot_index].signals[n].n_data=0;
   plot[plot_index].signals[n].min=0;//PLOT_DEF_MIN;
   plot[plot_index].signals[n].max=0;//PLOT_DEF_MAX;
   plot[plot_index].signals[n].x=0;
   plot[plot_index].signals[n].scale=1;
   plot[plot_index].n_signals++;
}

//---------------------------------------------------------------------------

void canvas_plot_thread::addData(int plot_index, int sig_index, int data){
   int n;

   n=plot[plot_index].signals[sig_index].n_data;

   plot[plot_index].signals[sig_index].data.resize(n+1);
   plot[plot_index].signals[sig_index].data[n]=data;
   if (data<plot[plot_index].signals[sig_index].min) plot[plot_index].signals[sig_index].min=data;
   if (data>plot[plot_index].signals[sig_index].max) plot[plot_index].signals[sig_index].max=data;
   plot[plot_index].signals[sig_index].n_data++;
   plotSample(plot_index, sig_index, n);
   //refreshSignal(plot_index, sig_index);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::addData(int plot_index, int sig_index, int *data, int size){
   int n;
   int i;

   n=plot[plot_index].signals[sig_index].n_data;

   plot[plot_index].signals[sig_index].data.resize(n+size);

   for (i=0; i<size; i++){
      plot[plot_index].signals[sig_index].data[n+i]=data[i];
      if (data[i]<plot[plot_index].signals[sig_index].min) plot[plot_index].signals[sig_index].min=data[i];
      if (data[i]>plot[plot_index].signals[sig_index].max) plot[plot_index].signals[sig_index].max=data[i];
      plot[plot_index].signals[sig_index].n_data++;
      plotSample(plot_index, sig_index, n+i);
   }
}

//---------------------------------------------------------------------------

void canvas_plot_thread::setSignalColor(int plot_index, int sig_index, TColor color){
   plot[plot_index].signals[sig_index].color=color;
}

//---------------------------------------------------------------------------

void canvas_plot_thread::removeSignal(int plot_index, int sig_index){
   int i;
   int n;

   clearSignal(plot_index, sig_index);

   n=plot[plot_index].n_signals;

   if (sig_index<(n-1)){
      for (i=sig_index; i<n-1; i++) plot[plot_index].signals[i]=plot[plot_index].signals[i+1];
   }

   if (n>0) plot[plot_index].signals.resize(n-1);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::clearPlot(int plot_index){
   int i;

   setupPlot(plot_index);

   for (i=0; i<plot[plot_index].n_signals; i++){
      plot[plot_index].signals[i].x=0;
      plot[plot_index].signals[i].data.resize(0);
      plot[plot_index].signals[i].n_data=0;
   }
}

//---------------------------------------------------------------------------

void canvas_plot_thread::clearSignal(int plot_index, int sig_index){
   clearCanvasSignal(plot_index, sig_index);
   drawCanvasGrid(plot_index);
   plot[plot_index].signals[sig_index].data.resize(0);
   plot[plot_index].signals[sig_index].n_data=0;
   plot[plot_index].signals[sig_index].x=0;
}

//---------------------------------------------------------------------------

void canvas_plot_thread::setupPlot(int plot_index){
   p_index_s=plot_index;
   setCanvasBackground(plot_index);
   drawCanvasGrid(plot_index);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::plotSample(int plot_index, int sig_index, int n){
   //int n;
   float scale_c;
   float scale_s;
   float scale;
   TColor color;

   //n=plot[plot_index].signals[sig_index].n_data;

   if (n>plot[plot_index].d_width) clearSignal(plot_index, sig_index);
   else{
      sample=plot[plot_index].signals[sig_index].data[n];
      scale_s=plot[plot_index].signals[sig_index].scale;
      scale_c=plot[plot_index].scale;

      scale=scale_c*scale_s;

      sample=adjustSampleRange(plot_index, sig_index, sample, scale);

      last_sample=plot[plot_index].signals[sig_index].data[n-1];
      last_sample=adjustSampleRange(plot_index, sig_index, last_sample, scale);

      color=plot[plot_index].signals[sig_index].color;

      plotCanvas(plot_index, sig_index, color);
   }
}

//---------------------------------------------------------------------------

void canvas_plot_thread::refreshSignal(int plot_index, int sig_index){
   int i;
   int n;

   clearCanvasSignal(plot_index, sig_index);

   n=plot[plot_index].signals[sig_index].n_data;

   for (i=0; i<n; i++) plotSample(plot_index, sig_index, i);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::resizePlot(int plot_index, int height, int width){
   plot[plot_index].c_height=height;
   plot[plot_index].c_width=width;

   plot[plot_index].d_height=height-2*PLOT_MARGIN;
   plot[plot_index].d_width=width-2*PLOT_MARGIN;

   p_index_s=plot_index;
   setCanvasBackground(plot_index);
   drawCanvasGrid(plot_index);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::plotCanvas(int plot_index, int sig_index, TColor color){
   int x;
   int adjust;

   adjust=plot[plot_index].c_height-1;

   setPenColor(plot_index, color);
   x=plot[plot_index].signals[s_index_s].x;

   if (x==0) moveTo(plot_index, x+PLOT_MARGIN, -sample+adjust);
   else{
      moveTo(plot_index, x+PLOT_MARGIN-1, -last_sample+adjust);
      lineTo(plot_index, x+PLOT_MARGIN, -sample+adjust);
   }

   plot[plot_index].signals[sig_index].x++;
}

//---------------------------------------------------------------------------

void canvas_plot_thread::clearCanvasSignal(int plot_index, int sig_index){
   int i, n;
   int sample;
   float scale_c;
   float scale_s;
   float scale;
   TColor background;
   int adjust;

   n=plot[plot_index].signals[sig_index].n_data;

   if (n>0){
      adjust=plot[plot_index].c_height;

      background=plot[plot_index].background;
      setPenColor(plot_index, background);

      sample=plot[plot_index].signals[sig_index].data[0];
      scale_s=plot[plot_index].signals[sig_index].scale;
      scale_c=plot[plot_index].scale;

      scale=scale_c*scale_s;

      sample=adjustSampleRange(plot_index, sig_index, sample, scale);
      moveTo(plot_index, PLOT_MARGIN, -sample+adjust);

      for (i=1; i<n; i++){
         sample=plot[plot_index].signals[sig_index].data[i];
         sample=adjustSampleRange(plot_index, sig_index, sample, scale);
         lineTo(plot_index, i+PLOT_MARGIN, -sample+adjust);
      }
   }
}

//---------------------------------------------------------------------------

void canvas_plot_thread::setCanvasBackground(int plot_index){
   int height, width;
   TColor background;

   height=plot[p_index_s].c_height;
   width=plot[p_index_s].c_width;
   background=plot[p_index_s].background;

   setPenColor(plot_index, background);
   setBrushColor(plot_index, background);
   drawRectangle(plot_index, 0, 0, width, height);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::drawCanvasGrid(int plot_index){
   int height, width;
   int center;
   int line;

   height=plot[plot_index].c_height-PLOT_MARGIN;
   width=plot[plot_index].c_width-PLOT_MARGIN;

   //retângulo externo
   setPenColor(plot_index, PLOT_DEF_GRID_COLOR);
   drawRectangle(plot_index, PLOT_MARGIN, PLOT_MARGIN, width, height);

   //linha horizontal de centro
   center=plot[plot_index].c_height/2;
   moveTo(plot_index, PLOT_MARGIN, center);
   lineTo(plot_index, width, center);

   setPenStyle(plot_index, psDot);

   //grid horizontal inferior
   line=center+PLOT_DEF_GRID;
   while (line<height){
      moveTo(plot_index, PLOT_MARGIN, line);
      lineTo(plot_index, width, line);
      line+=PLOT_DEF_GRID;
   }

   //grid horizontal superior
   line=center-PLOT_DEF_GRID;
   while (line>PLOT_MARGIN){
      moveTo(plot_index, PLOT_MARGIN, line);
      lineTo(plot_index, width, line);
      line-=PLOT_DEF_GRID;
   }

   //grid vertical
   line=PLOT_MARGIN+PLOT_DEF_GRID;
   while (line<width){
      moveTo(plot_index, line, PLOT_MARGIN);
      lineTo(plot_index, line, height);
      line+=PLOT_DEF_GRID;
   }

   setPenStyle(plot_index, psSolid);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::setPenColor(int plot_index, TColor color){
   p_index_s=plot_index;
   color_s=color;
   Synchronize(&setPenColorS);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::setPenStyle(int plot_index, TPenStyle style){
   p_index_s=plot_index;
   style_s=style;
   Synchronize(&setPenStyleS);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::setBrushColor(int plot_index, TColor color){
   p_index_s=plot_index;
   color_s=color;
   Synchronize(&setBrushColorS);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::moveTo(int plot_index, int x, int y){
   p_index_s=plot_index;
   x1_s=x;
   y1_s=y;
   Synchronize(&moveToS);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::lineTo(int plot_index, int x, int y){
   p_index_s=plot_index;
   x1_s=x;
   y1_s=y;
   Synchronize(&lineToS);
}

//---------------------------------------------------------------------------

void canvas_plot_thread::drawRectangle(int plot_index, int x1, int y1, int x2, int y2){
   p_index_s=plot_index;
   x1_s=x1;
   y1_s=y1;
   x2_s=x2;
   y2_s=y2;
   Synchronize(&drawRectangleS);
}

//---------------------------------------------------------------------------

void __fastcall canvas_plot_thread::setPenColorS(void){
   plot[p_index_s].canvas->Pen->Color=color_s;
}

//---------------------------------------------------------------------------

void __fastcall canvas_plot_thread::setPenStyleS(void){
   plot[p_index_s].canvas->Pen->Style=style_s;
}

//---------------------------------------------------------------------------

void __fastcall canvas_plot_thread::setBrushColorS(void){
   plot[p_index_s].canvas->Brush->Color=color_s;
}

//---------------------------------------------------------------------------

void __fastcall canvas_plot_thread::moveToS(void){
   plot[p_index_s].canvas->MoveTo(x1_s, y1_s);
}

//---------------------------------------------------------------------------

void __fastcall canvas_plot_thread::lineToS(void){
   plot[p_index_s].canvas->LineTo(x1_s, y1_s);
}

//---------------------------------------------------------------------------

void __fastcall canvas_plot_thread::drawRectangleS(void){
   plot[p_index_s].canvas->Rectangle(x1_s, y1_s, x2_s, y2_s);
}

//---------------------------------------------------------------------------

int canvas_plot_thread::adjustSampleRange(int plot_index, int sig_index, int sample, float scale){
   int min;
   int max;

   min=PLOT_DEF_MIN;//plot[plot_index].signals[sig_index].min;
   max=PLOT_DEF_MAX;//plot[plot_index].signals[sig_index].max;

   return adjustRange(sample, min, max, PLOT_MARGIN, plot[plot_index].c_height-PLOT_MARGIN, scale);
}

//---------------------------------------------------------------------------

int canvas_plot_thread::adjustRange(int x, int in_min, int in_max, int out_min, int out_max, float scale){
   int xs;
   int diff_in;

   xs=(int)((double)x*(double)scale);

   diff_in=in_max-in_min;

   if (diff_in==0) diff_in=1;

   //return (xs - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
   return (xs - in_min) * (out_max - out_min) / diff_in + out_min;
}

//---------------------------------------------------------------------------
