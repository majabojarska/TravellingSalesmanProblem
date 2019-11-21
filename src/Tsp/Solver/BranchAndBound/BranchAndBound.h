#ifndef SRC_BRANCHANDBOUND_H
#define SRC_BRANCHANDBOUND_H

#include <queue>

#include "../../Constants.h"
#include "../GenericSolver.h"
#include "PartSolution.h"
#include "PartSolutionComparator.h"

namespace solver {

    // Least cost branch and bound
    class BranchAndBound : public GenericSolver {
    public:
        BranchAndBound();

        void setTsp(const shared_ptr<TSP> &tsp) override;

        shared_ptr<Route> getSolution() override;

    };

} // namespace solver
#endif // SRC_BRANCHANDBOUND_H
