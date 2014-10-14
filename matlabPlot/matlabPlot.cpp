#include "matlabPlot.hpp"

matlabPlot::matlabPlot(std::string filename) : file_name(filename) {};

plotFigure *matlabPlot::addFigure(void) {
    figures.push_back(plotFigure());

    return &figures.back();
}

plotFigure *matlabPlot::addFigure(plotTypes type,plotColors color) {
    plotFigure temp;
    temp.setColor(color);
    temp.setType (type);
    figures.push_back(temp);

    return &figures.back();
}

plotFigure *matlabPlot::addFigure(plotFigure &figure) {
    figures.push_back(figure);

    return &figure;
}

bool matlabPlot::saveFile(void) const {
    std::ofstream file(file_name.c_str());
    if (!file.is_open()) return 0;

    file << "close all;" << std::endl << std::endl;
    for (auto &f : figures) {
        file << f.getMatlabCode();
        file << std::endl << std::endl;
    }

    file.close();

    return 1;
}
