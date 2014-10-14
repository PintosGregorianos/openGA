#include <iostream>

#include "matPlot.hpp"

const float dado[10]  = {0.f,1.f,2.f,0.f,1.f,2.f,0.f,2.f,4.f,6.f};
const float dado2[10] = {6.f,3.f,-2.f,0.f,9.f,-1.f,0.f,-2.f,4.f,3.f};

int main() {
    matPlot::File myplot("teste_matlab");

    matPlot::Figure *plot1 = myplot.addFigure(matPlot::Types::plot,matPlot::Colors::red);
    plot1->setDataX(dado,10);

    matPlot::Figure *plot2 = myplot.addFigure(matPlot::Types::scatter,matPlot::Colors::green);
    plot2->setDataX(dado ,10);
    plot2->setDataY(dado2,10);

    if (!myplot.save())
        std::cout << "Erro ao salvar o arquivo." << std::endl;

    return 0;
}
