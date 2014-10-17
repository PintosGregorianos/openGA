#include "polySpace.hpp"

void polySpace::randomizePoly(void) {
    for (auto &d : my_coeffs) {
        for (auto &x : d) {
            x = 2.f*real_rand() - 1.f;
        }
    }
}

polySpace::polySpace(std::size_t dimensions,std::size_t size,std::size_t order) {
    n_coeffs = order;
    resize(dimensions,size);
    my_coeffs.resize(dimensions);
    for (auto &x : my_coeffs) x.resize(order);

    randomizePoly();
    generate();
}

void polySpace::setOrder(std::size_t order) {
    n_coeffs = order;
    for (auto &x : my_coeffs) x.resize(order);
}

const float *polySpace::getDimensionCoefficients(std::size_t dimension) const {
    return &my_coeffs[dimension].front();
}

float polySpace::getCoefficient(std::size_t dimension,std::size_t coefficient) const {
    return my_coeffs[dimension][coefficient];
}

void polySpace::generate(void) {
    randomizePoly();

    const float step = 2.f / (float)size;
    for (std::size_t d = 0; d < dimensions; d++) {
        float x = -1.f;
        for (std::size_t i = 0; i < size; i++,x += step) {
            float temp = 0.f;
            for (std::size_t c = 0; c < n_coeffs; c++) {
                temp += my_coeffs[d][c]*pow(x,c);
            }
            my_space[d][i] = temp;
        }
    }
}
