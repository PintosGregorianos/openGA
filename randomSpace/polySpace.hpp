#include <vector>

#include "randomSpace.hpp"
//#include "rand.hpp"

class polySpace : public randomSpace {
    private:
        std::size_t n_polys;
        std::vector<float>polys;

    public:
        polySpace(std::size_t dimensions,std::size_t size,std::size_t order) {
            n_polys = order;
            resize(dimensions,size);
        }

        void setOrder(std::size_t order) {
            n_polys = order;
        }

        const float *getCoefficients(void) const {
            return &polys.front();
        }

        float getCoefficient(std::size_t coefficient) const {
            return polys[coefficient];
        }

        void generate(void) {

        }



};
