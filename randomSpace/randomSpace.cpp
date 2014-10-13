#include "randomSpace.hpp"


void randomSpace::construct(void) {
 	my_space.resize(dimensions);
	for (auto &&x : my_space) x.resize(size);
}

const float *randomSpace::getDimension(size_t dimension) const {
	return &my_space[dimension].front();
}

float randomSpace::getValueAt(size_t dimension, size_t position) const {
	return my_space[dimension][position];
}

space randomSpace::getDownscaledSpace(size_t downscale_factor) const {

}

void randomSpace::resize(size_t size,size_t dimensions) {
	this->size       = size;
	this->dimensions = dimensions;

	construct();
}
