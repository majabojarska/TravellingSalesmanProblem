#include "BruteForce.h"

using namespace solver;

BruteForce::BruteForce() : GenericSolver() {}

shared_ptr<Route> BruteForce::getSolution() {
    performBruteforceSearch();
    return optimalRoute;
}

void BruteForce::performBruteforceSearch() {
    permuteRecursive(1, tsp->getNodeCount() - 1);
}

void BruteForce::permuteRecursive(unsigned int startIndex,
                                  unsigned int endIndex) {
    if (startIndex == endIndex) {
        unsigned int currentRouteCost = tsp->getCycleCost(currentRoute);
//        std::cout << "Current Route: " << currentRoute->toString(false)
//                  << " | Cost: " << currentRouteCost;
        if (currentRouteCost < optimalRouteCost) {
            optimalRouteCost = currentRouteCost;
            optimalRoute = make_shared<Route>(currentRoute);
//            std::cout << " | New best cost: " << optimalRouteCost;
        }
//        std::cout << endl;
    } else {
        for (unsigned int i = startIndex; i <= endIndex; i++) {
            currentRoute->swapNodes(startIndex, i);
            permuteRecursive(startIndex + 1, endIndex);
            currentRoute->swapNodes(startIndex, i);
        }
    }
}

void BruteForce::setTsp(const shared_ptr<TSP> &tsp) {
    this->tsp = tsp;
    currentRoute = std::make_shared<Route>(tsp->getNodeCount());
    optimalRouteCost = UINT32_MAX;

}
