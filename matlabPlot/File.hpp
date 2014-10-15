#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "enums.hpp"
#include "Figure.hpp"

namespace matPlot {
    class File;

};

class matPlot::File {
        private:
            const std::string file_name;
            std::vector<matPlot::Figure>figures;

        public:
            File(std::string filename);

            Figure *addFigure(void);

            matPlot::Figure *addFigure(Types type,Colors color);

            Figure *addFigure(Figure &figure);

            bool save(void) const;
    };
