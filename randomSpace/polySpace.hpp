#pragma once

#include <vector>
#include <cmath>

#include "randomSpace.hpp"
#include "rand.hpp"

//O coment‡rio entre > Ž extremamente necess‡rio!
using coeffs = std::vector<std::vector<float>/**/>;

class polySpace : public randomSpace {
    private:
        std::size_t n_coeffs;
        coeffs my_coeffs;

        void randomizePoly(void);

    public:
        polySpace(std::size_t dimensions,std::size_t size,std::size_t order);

        void setOrder(std::size_t order);

        const float *getDimensionCoefficients(std::size_t dimension) const;

        float getCoefficient(std::size_t dimension,std::size_t coefficient) const;

        void generate(void);
};
