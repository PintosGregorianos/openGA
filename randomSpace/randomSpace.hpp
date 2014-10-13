#pragma once

#include <vector>

using space = std::vector<std::vector<float>/**/>;

class randomSpace {
	private:
		 size_t size;
		 size_t dimensions;

		 space my_space;

		 void construct(void);

	public:
		void resize(size_t dimensions,size_t size);

		const float *getDimension(size_t dimension) const;

		float getValueAt(size_t dimension, size_t position) const;

		space getDownscaledSpace(size_t downscale_factor) const;

		virtual void gererate(void) = 0;
};
