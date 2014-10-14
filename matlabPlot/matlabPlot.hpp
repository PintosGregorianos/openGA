#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

#include "plotFigure.hpp"

enum class plotTypes {
    plot,scatter,stem
};

enum class plotColors {
    red,blue,green,yellow,black,cyan,magenta
};

class matlabPlot {
    private:
        const std::string file_name;
        std::vector<plotFigure>figures;

    public:
        matlabPlot(std::string filename) : file_name(filename) {};

        plotFigure *addFigure(void) {
            figures.push_back(plotFigure());

            return &figures.back();
        }

        plotFigure *addFigure(plotTypes type,plotColors color) {
            plotFigure temp;
            temp.setColor(color);
            temp.setType (type);
            figures.push_back(temp);

            return &figures.back();
        }

        plotFigure *addFigure(plotFigure &figure) {
            figures.push_back(figure);

            return &figure;
        }

        bool saveFile(void) const {
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
};
