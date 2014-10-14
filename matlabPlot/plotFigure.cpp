#include "plotFigure.hpp"

std::string plotFigure::getMatlabCode() const {
    std::string code;
    switch (type) {
        case (plotTypes::plot):
            code += "plot";
            break;

        case (plotTypes::scatter):
            code += "scatter";
            break;

        case (plotTypes::stem):
            code += "stem";
            break;
    }

    code += "([";

    if (!datax.empty()) code += std::to_string(datax.front());
    for (std::size_t i = 1; i < datax.size(); i++)
        code += "," + std::to_string(datax[i]);

    code += "]";

    if (!datay.empty()) {
        code += ",[" + std::to_string(datay.front());
        for (std::size_t i = 1; i < datay.size(); i++)
            code += "," + std::to_string(datay[i]);

        code += "]";
    }

    code += ",'";

    const char colors[7] = {'r','b','g','y','k','c','m'};
    code += colors[static_cast<size_t>(color)];

    code += "');";

    return code;
}

plotFigure::plotFigure() {
    color = plotColors::blue;
    type  = plotTypes::plot;
}

void plotFigure::setDataX(std::vector<float> &data) {
    this->datax = data;
}

void plotFigure::setDataY(std::vector<float> &data) {
    this->datay = data;
}

void plotFigure::setDataX(const float *data, std::size_t size) {
    this->datax.resize(size);
    for (std::size_t i = 0; i < size; i++)
        this->datax[i] = data[i];
}

void plotFigure::setDataY(const float *data, std::size_t size) {
    this->datay.resize(size);
    for (std::size_t i = 0; i < size; i++)
        this->datay[i] = data[i];
}

void plotFigure::setColor(plotColors color) {
    this->color = color;
}

void plotFigure::setType(plotTypes type) {
    this->type = type;
}
