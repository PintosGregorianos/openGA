#include "File.hpp"

namespace matPlot {
    File::File(std::string filename) : file_name(filename) {};

    Figure *File::addFigure(void) {
        figures.push_back(Figure());

        return &figures.back();
    }

    Figure *File::addFigure(Types type,Colors color) {
        Figure temp;
        temp.setColor(color);
        temp.setType (type);
        figures.push_back(temp);

        return &figures.back();
    }

    Figure *File::addFigure(Figure &figure) {
        figures.push_back(figure);

        return &figure;
    }

    bool File::save(void) const {
        std::ofstream file((file_name + ".m").c_str());
        if (!file.is_open()) return 0;

        file << "close all;" << std::endl << std::endl;
        for (auto &f : figures) {
            file << "figure;" << std::endl;
            file << f.getMatlabCode();
            file << std::endl << std::endl;
        }

        file.close();

        return 1;
    }
};
