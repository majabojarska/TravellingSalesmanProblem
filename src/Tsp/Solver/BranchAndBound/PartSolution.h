#ifndef SRC_PARTSOLUTION_H
#define SRC_PARTSOLUTION_H

#include <algorithm>
#include <memory>

#include "../../Constants.h"
#include "../../CostMatrix.h"
#include "../../Route.h"

class PartSolution {

public:
    explicit PartSolution(const shared_ptr<CostMatrix> &inputCostMatrix);

    explicit PartSolution(const shared_ptr<PartSolution> &inputPartSolution);

    int reduceCostMatrix();

    void prohibitBacktrack(unsigned int sourceNode, unsigned int targetNode);

    string toString();

    int lowerBound = INT32_MAX;
    shared_ptr<CostMatrix> costMatrix = nullptr;
    shared_ptr<Route> route = nullptr;

protected:
    int getMinValueInRow(unsigned int rowNum);

    int getMinValueInCol(unsigned int colNum);

    static int getMinValueInVector(const vector<int> &targetVector);

    int reduceRows();

    int reduceCols();
};

#endif // SRC_PARTSOLUTION_H
