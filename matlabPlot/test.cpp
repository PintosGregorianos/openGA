#include <iostream>

#include "matlabPlot.hpp"

const float dado[10]  = {0.f,1.f,2.f,0.f,1.f,2.f,0.f,2.f,4.f,6.f};
const float dado2[10] = {6.f,3.f,-2.f,0.f,9.f,-1.f,0.f,-2.f,4.f,3.f};

int main() {

    matlabPlot myplot("teste_matlab");

    plotFigure *plot1 = myplot.addFigure(plotTypes::plot,plotColors::red);
    plot1->setDataX(dado,10);

    plotFigure *plot2 = myplot.addFigure(plotTypes::scatter,plotColors::green);
    plot2->setDataX(dado,10);
    plot2->setDataY(dado2,10);

    if (!myplot.saveFile())
        std::cout << "Erro ao salvar o arquivo." << std::endl;

    return 0;
}
