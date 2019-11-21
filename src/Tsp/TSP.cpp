#include "TSP.h"

TSP::TSP(unsigned int nodeCount) {
    this->costMatrix = make_shared<CostMatrix>(nodeCount);
}
//
//TSP::TSP(TSP &tsp) {
//    this->costMatrix = make_shared<CostMatrix>(tsp.costMatrix);
//}

TSP::TSP() {}


TSP TSP::loadFromFile(const string &pathToFile) {
    CostMatrix costMatrix = CostMatrix::fromTextFile(pathToFile);
    TSP tsp;
    tsp.costMatrix = make_shared<CostMatrix>(costMatrix);
    return tsp;
}

unsigned int TSP::getNodeCount() {
    return this->costMatrix->getNodeCount();
}

unsigned int TSP::getRouteCost(Route &route) {
    unsigned int routeCost = 0;
    auto nodes = route.routeNodes;
    for (unsigned int i = 0; i < nodes.size() - 1; i++) {
        routeCost +=
                this->costMatrix->getCost(nodes.at(i),
                                          nodes.at(i + 1)
                );
    }

    return routeCost;
}

unsigned int TSP::getRouteCost(const shared_ptr<Route> &route) {
    return getRouteCost(*route);
}

unsigned int TSP::getCycleCost(Route &route) {
    unsigned int cycleCost = 0;
    cycleCost += getRouteCost(route);

    auto nodes = route.routeNodes;
    cycleCost += this->costMatrix->getCost(
            nodes.at(nodes.size() - 1),
            nodes.at(0)
    );

    return cycleCost;
}

unsigned int TSP::getCycleCost(const shared_ptr<Route> &route) {
    return getCycleCost(*route);
}

const shared_ptr<CostMatrix> &TSP::getCostMatrix() { return costMatrix; }

string TSP::toString() {
    stringstream os;
    os << "Node count: " << getNodeCount() << "\n\n";
    os << costMatrix->toString();
    os << flush;
    return os.str();
}

TSP TSP::getRandomSymmetric(unsigned int nodeCount) {
    TSP tsp(nodeCount);
    tsp.costMatrix = make_shared<CostMatrix>(CostMatrix::getRandomSymmetric(nodeCount));
    return tsp;
}

TSP TSP::getRandomAsymmetric(unsigned int nodeCount) {
    TSP tsp(nodeCount);
    tsp.costMatrix = make_shared<CostMatrix>(CostMatrix::getRandomAsymmetric(nodeCount));
    return tsp;
}

void TSP::setCostMatrix(const CostMatrix &costMatrix) {
    this->costMatrix = make_shared<CostMatrix>(costMatrix);
}


//
//TSP &TSP::operator=(shared_ptr<TSP> tsp) {
//    TSP newTsp;
//    newTsp.costMatrix = make_shared<CostMatrix>(tsp->getCostMatrix());
//    return newTsp;
//}
