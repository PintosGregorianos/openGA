#include "Figure.hpp"

namespace matPlot {
    std::string Figure::getMatlabCode() const {
        std::string code;
        switch (type) {
            case (Types::plot):
                code += "plot";
                break;

            case (Types::scatter):
                code += "scatter";
                break;

            case (Types::stem):
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

    Figure::Figure() {
        color = matPlot::Colors::blue;
        type  = matPlot::Types::plot;
    }

    void Figure::setDataX(std::vector<float> &data) {
        this->datax = data;
    }

    void Figure::setDataY(std::vector<float> &data) {
        this->datay = data;
    }

    void Figure::setDataX(const float *data, std::size_t size) {
        this->datax.resize(size);
        for (std::size_t i = 0; i < size; i++)
            this->datax[i] = data[i];
    }

    void Figure::setDataY(const float *data, std::size_t size) {
        this->datay.resize(size);
        for (std::size_t i = 0; i < size; i++)
            this->datay[i] = data[i];
    }

    void Figure::setColor(matPlot::Colors color) {
        this->color = color;
    }

    void Figure::setType(Types type) {
        this->type = type;
    }
};
