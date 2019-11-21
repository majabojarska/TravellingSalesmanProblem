#include "UniformRand.h"
#include <ctime>

UniformRand::UniformRand(int min, int max) {
    this->twisterEngine = std::mt19937(static_cast<long unsigned int>(time(nullptr)));
    this->uniformIntDistribution = std::uniform_int_distribution<>(min, max);
}

int UniformRand::getRandomInt() {
    return uniformIntDistribution(twisterEngine);
}
