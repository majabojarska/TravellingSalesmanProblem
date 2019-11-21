#include "DynamicProg.h"

using namespace solver;

DynamicProg::DynamicProg() : GenericSolver() {}

shared_ptr<Route> DynamicProg::getSolution() {
    NodeSet intermediateNodes = (1 << (tsp->getNodeCount() - 1)) - 1;

    getSubSolution(DEFAULT_START_NODE_NUM, intermediateNodes);

    int lastVisitedNode = DEFAULT_START_NODE_NUM;
    auto routeNodes = vector<unsigned int>();
    routeNodes.push_back(lastVisitedNode);
    for (unsigned int i = 0; i < tsp->getNodeCount() - 1; i++) {
        routeNodes.push_back(successorNodes[lastVisitedNode][intermediateNodes]);
        lastVisitedNode = routeNodes.back();
        intermediateNodes = markAsVisited(intermediateNodes, lastVisitedNode);
    }
    auto optimalRoute = make_shared<Route>(routeNodes);

    return optimalRoute;
}

unsigned int DynamicProg::getSubSolution(unsigned int sourceNode, NodeSet intermediateNodes) {
    int minCost = INT32_MAX;

    if (bestCost[sourceNode][intermediateNodes] == INFINITE_COST) {
        for (unsigned int targetNode = 1; targetNode < tsp->getNodeCount(); targetNode++) {
            if (sourceNode == targetNode || isVisited(targetNode, intermediateNodes)) {
                continue;
            }
            NodeSet intermediateNodesSubset = markAsVisited(intermediateNodes, targetNode);
            int currentCost =
                    tsp->getCostMatrix()->getCost(sourceNode, targetNode) +
                    getSubSolution(targetNode, intermediateNodesSubset);
            if (currentCost < minCost) {
                minCost = currentCost;
                successorNodes[sourceNode][intermediateNodes] = targetNode;
            }
        }
        bestCost[sourceNode][intermediateNodes] = minCost;
    }
    return bestCost[sourceNode][intermediateNodes];
}

bool DynamicProg::isVisited(unsigned int targetNode, NodeSet nodesToVisit) {
    return (nodesToVisit & (1 << (targetNode - 1))) == 0;
}

NodeSet DynamicProg::getInitIntermediateNodes(unsigned int nodeCount) {
    return 1 << (nodeCount - 1);
}

NodeSet DynamicProg::markAsVisited(NodeSet intermediateNodes, unsigned int visitedNode) {
    NodeSet result = intermediateNodes & ~(1 << (visitedNode - 1));
    return result;
}

void DynamicProg::setTsp(const shared_ptr<TSP> &tsp) {
    this->tsp = tsp;

    unsigned int nodeCount = tsp->getNodeCount();

    this->bestCost = vector<vector<int>>(nodeCount);
    this->successorNodes = vector<vector<int>>(nodeCount);

    for (unsigned int sourceNode = 0; sourceNode < nodeCount; sourceNode++) {
        bestCost[sourceNode] = vector<int>(
                getInitIntermediateNodes(nodeCount),
                INFINITE_COST);
        bestCost[sourceNode][0] =
                tsp->getCostMatrix()->getCost(sourceNode, 0);
        successorNodes[sourceNode] = vector<int>(
                getInitIntermediateNodes(nodeCount),
                INFINITE_COST);
    }
}

