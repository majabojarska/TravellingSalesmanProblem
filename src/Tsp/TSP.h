#ifndef SRC_TSP_H
#define SRC_TSP_H

#include <iterator>
#include <memory>
#include <vector>

#include "CostMatrix.h"
#include "Route.h"

class TSP {
public:
    explicit TSP(unsigned int nodeCount);

    TSP();

//    TSP(TSP &tsp);

//    TSP &operator=(shared_ptr<TSP> tsp);

    static TSP getRandomSymmetric(unsigned int nodeCount);

    static TSP getRandomAsymmetric(unsigned int nodeCount);

    unsigned int getRouteCost(Route &route);

    unsigned int getRouteCost(const shared_ptr<Route> &route);

    unsigned int getCycleCost(Route &route);

    unsigned int getCycleCost(const shared_ptr<Route> &route);

    unsigned int getNodeCount();

    const shared_ptr<CostMatrix> &getCostMatrix();

    void setCostMatrix(const CostMatrix &costMatrix);

    static TSP loadFromFile(const string &pathToFile);

    string toString();
private:
    shared_ptr<CostMatrix> costMatrix = nullptr;
};

#endif //SRC_TSP_H
