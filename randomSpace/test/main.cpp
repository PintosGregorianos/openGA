#include <iostream>

#include "polySpace.hpp"
#include "matPlot.hpp"


int main() {
    // Cria espaco 1d com tamanho 256 e polinomio de ordem 13
    const std::size_t size = 256;
    polySpace space(1,size,13);

    const float *d = space.getDimension(0);

    // Gera arquivo de plot
    matPlot::File file("space_plot");

    matPlot::Figure *fig0 = file.addFigure(matPlot::Types::plot,matPlot::Colors::red);
    fig0->setDataX(d,size);

    file.save();

    return 0;
}
