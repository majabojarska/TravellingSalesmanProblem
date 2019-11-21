#ifndef SRC_BRUTEFORCE_H
#define SRC_BRUTEFORCE_H

#include "../GenericSolver.h"
#include <algorithm>
#include <iostream>

namespace solver {

    class BruteForce : public GenericSolver {
    public:
        explicit BruteForce();

        shared_ptr<Route> getSolution() override;

        void setTsp(const shared_ptr<TSP> &tsp) override;

    protected:
        shared_ptr<Route> currentRoute;
        shared_ptr<Route> optimalRoute;
        unsigned int optimalRouteCost;

        void performBruteforceSearch();

        void permuteRecursive(unsigned int startIndex, unsigned int endIndex);
    };

} // namespace solver
#endif //SRC_BRUTEFORCE_H
