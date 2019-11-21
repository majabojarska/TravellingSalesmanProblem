#ifndef SRC_UNIFORMRAND_H
#define SRC_UNIFORMRAND_H
#include <random>

class UniformRand {
public:
    UniformRand(int min, int max);
    int getRandomInt();
private:
    std::uniform_int_distribution<> uniformIntDistribution;
    std::mt19937 twisterEngine;
};


#endif //SRC_UNIFORMRAND_H
