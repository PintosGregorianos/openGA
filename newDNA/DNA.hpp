#include <vector>
#include <random>
#include <array>
#include <limits>

namespace DNA {
    std::random_device         rand_device;
    std::default_random_engine rand_engine(rand_device());


    //template<class T>
    //auto binaryChromGen = std::bind(std::uniform_int_distribution<T>(std::numeric_limits<T>::min(), std::numeric_limits<T>::max()),rand_engine);

    template<class T>
    T binaryChromGen(void);

    template<class T,std::size_t SIZE>
    using binaryChromContainer = std::array<T,SIZE>;

    /*template<class T,std::size_t SIZE>
    using realChromContainer = binaryChromContainer<T,SIZE>;
    */
    class father {

        public:
            //virtual void crossover(const father *other) = 0;
            virtual void mutation (void) = 0;
    };


    template<class T, std::size_t SIZE>
    class binary : public father {

        binaryChromContainer<T,SIZE> m_container;

        public:
            binary();
            const T* accessChromossomes(void)                      const;
            T        getChromossome    (std::size_t chrom_id)      const;
            binaryChromContainer<T,SIZE> getChromossomes(void)     const;

            void mutation(void);
    };
};


template<class T, std::size_t SIZE>
const T* DNA::binary<T,SIZE>::accessChromossomes(void) const {
    return &m_container.front();
}

template<class T, std::size_t SIZE>
DNA::binaryChromContainer<T,SIZE> DNA::binary<T,SIZE>::getChromossomes(void) const {
    return m_container;
}

template<class T, std::size_t SIZE>
T DNA::binary<T,SIZE>::getChromossome(std::size_t chrom_id) const {
    return m_container[chrom_id];
}

template<class T, std::size_t SIZE>
void DNA::binary<T,SIZE>::mutation(void) {
    for (std::size_t i = 0; i < SIZE; i++)
        m_container[i] ^= DNA::binaryChromGen<T>();
}

template<class T,std::size_t SIZE>
DNA::binary<T,SIZE>::binary() {
    for (std::size_t i = 0; i < SIZE; i++)
        m_container[i] = DNA::binaryChromGen<T>();
}

template<class T>
T DNA::binaryChromGen(void) {
    static std::uniform_int_distribution<T> dist(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
    return dist(rand_engine);
}
