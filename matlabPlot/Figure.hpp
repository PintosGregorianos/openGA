#pragma once

#include <string>
#include <vector>

#include "enums.hpp"


namespace matPlot {
    class Figure {
        friend class File;
        private:
            Types  type;
            Colors color;
            std::vector<float>datax,datay;

        protected:
            std::string getMatlabCode() const;

        public:
            Figure();

            void setDataX(std::vector<float> &data);

            void setDataY(std::vector<float> &data);

            void setDataX(const float *data, std::size_t size);

            void setDataY(const float *data, std::size_t size);

            void setColor(Colors color);

            void setType(Types type);
    };
};
