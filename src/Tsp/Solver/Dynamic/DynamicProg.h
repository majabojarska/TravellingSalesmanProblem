#ifndef SRC_DYNAMICPROG_H
#define SRC_DYNAMICPROG_H

#include "../GenericSolver.h"

namespace solver {

    typedef unsigned int NodeSet;

    class DynamicProg : public GenericSolver {
    public:
        DynamicProg();

        void setTsp(const shared_ptr<TSP> &tsp) override;

        shared_ptr<Route> getSolution() override;

    private:
        vector<vector<int>> bestCost; // bestCost[sourceNode][viaThisNodeSet]
        vector<vector<int>> successorNodes;

        unsigned int getSubSolution(unsigned int sourceNode, NodeSet intermediateNodes);

        static bool isVisited(unsigned int targetNode, NodeSet nodesToVisit);

        static NodeSet getInitIntermediateNodes(unsigned int nodeCount);

        static NodeSet markAsVisited(NodeSet intermediateNodes, unsigned int visitedNode);
    };

} // namespace solver
#endif // SRC_DYNAMICPROG_H
