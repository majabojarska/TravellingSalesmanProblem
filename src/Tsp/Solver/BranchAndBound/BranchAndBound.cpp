#include "BranchAndBound.h"

using namespace solver;

BranchAndBound::BranchAndBound() : GenericSolver() {}

void BranchAndBound::setTsp(const shared_ptr<TSP> &tsp) {
    this->tsp = tsp;
}

shared_ptr<Route> BranchAndBound::getSolution() {
    std::priority_queue<
            shared_ptr<PartSolution>,
            vector<shared_ptr<PartSolution>>,
            PartSolutionComparator
    > partSolutionQueue;

    shared_ptr<PartSolution> rootSolution = make_shared<PartSolution>(tsp->getCostMatrix());
    rootSolution->route->routeNodes.push_back(DEFAULT_START_NODE_NUM);
    rootSolution->lowerBound = rootSolution->reduceCostMatrix();

    partSolutionQueue.push(rootSolution);

    shared_ptr<PartSolution> currentSolution = nullptr;

    while (!partSolutionQueue.empty()) {
        currentSolution = partSolutionQueue.top();
        partSolutionQueue.pop();
        if (currentSolution->route->routeNodes.size() == tsp->getNodeCount()) {
            break;
        }
        int sourceNode = currentSolution->route->routeNodes.back();
        for (size_t targetNode = 0; targetNode < tsp->getNodeCount(); targetNode++) {
            int sourceToTargetCost = currentSolution->costMatrix->getCost(sourceNode, targetNode);
            if (sourceToTargetCost == INFINITE_COST) {
                continue;
            }

            shared_ptr<PartSolution> nextLevelSolution = make_shared<PartSolution>(currentSolution);

            nextLevelSolution->prohibitBacktrack(sourceNode, targetNode);
            nextLevelSolution->route->routeNodes.push_back(targetNode);
            nextLevelSolution->lowerBound += nextLevelSolution->reduceCostMatrix() + sourceToTargetCost;

            partSolutionQueue.push(nextLevelSolution);
        }
    }
    return currentSolution->route;
}

