#pragma once

#include <vector>

//O comentário entre > é extremamente necessário!
using space = std::vector<std::vector<float>/**/>;

class randomSpace {
	private:
		 std::size_t size;
		 std::size_t dimensions;

		 space my_space;

		 void construct(void);

	public:
		void resize(std::size_t dimensions,std::size_t size);

		const float *getDimension(std::size_t dimension) const;

		float getValueAt(std::size_t dimension, std::size_t position) const;

		space getDownscaledSpace(std::size_t downscale_factor) const;

		virtual void gererate(void) = 0;
};
