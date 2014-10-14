#include "randomSpace.hpp"

void randomSpace::construct(void) {
 	my_space.resize(dimensions);
	for (auto &&x : my_space) x.resize(size);
}

const float *randomSpace::getDimension(std::size_t dimension) const {
	return &my_space[dimension].front();
}

float randomSpace::getValueAt(std::size_t dimension, std::size_t position) const {
	return my_space[dimension][position];
}

space randomSpace::getDownscaledSpace(std::size_t downscale_factor) const {
    space temp;
    temp.resize(dimensions);
    for (std::size_t i = 0; i < dimensions; i++) {
        temp[i].resize(size/downscale_factor);
        std::size_t k = 0;
        for (std::size_t j = 0; j < size ; j += downscale_factor, k++) {
            temp[i][k] = my_space[i][j];
        }
    }
    return temp;
}

void randomSpace::resize(std::size_t size,std::size_t dimensions) {
	this->size       = size;
	this->dimensions = dimensions;

	construct();
}
