#include "PartSolution.h"

PartSolution::PartSolution(const shared_ptr<CostMatrix> &inputCostMatrix) {
    costMatrix = make_shared<CostMatrix>(inputCostMatrix);
    route = make_shared<Route>();
}

PartSolution::PartSolution(const shared_ptr<PartSolution> &inputPartSolution) {
    this->route = make_shared<Route>(inputPartSolution->route);
    this->costMatrix = make_shared<CostMatrix>(inputPartSolution->costMatrix);
    this->lowerBound = inputPartSolution->lowerBound;
}

int PartSolution::getMinValueInRow(unsigned int rowNum) {
    auto targetRow = costMatrix->getRow(rowNum);
    return getMinValueInVector(targetRow);
}

int PartSolution::getMinValueInCol(unsigned int colNum) {
    auto targetCol = costMatrix->getCol(colNum);
    return getMinValueInVector(targetCol);
}

int PartSolution::getMinValueInVector(const vector<int> &targetVector) {
    int minVal = INT32_MAX;
    for (int i : targetVector) {
        if (i != INFINITE_COST && i < minVal) {
            minVal = i;
        }
    }
    if (minVal == INT32_MAX) {
        return 0;
    }
    return minVal;
}

int PartSolution::reduceCostMatrix() {
    return reduceRows() + reduceCols();
}

int PartSolution::reduceRows() {
    int totalRowReduction = 0;

    // Reduce each row.
    for (unsigned int rowNum = 0; rowNum < costMatrix->getNodeCount(); rowNum++) {
        int currentRowMinValue = getMinValueInRow(rowNum);

        // Reduce each node in current row
        if (currentRowMinValue != 0) {
            totalRowReduction += currentRowMinValue;
            for (unsigned int colNum = 0; colNum < costMatrix->getNodeCount(); colNum++) {
                int currentCostBetweenNodes = costMatrix->getCost(rowNum, colNum);
                if (currentCostBetweenNodes != INFINITE_COST) {
                    costMatrix->setCost(rowNum,
                                        colNum,
                                        currentCostBetweenNodes - currentRowMinValue);
                }

            }
        }
    }
    return totalRowReduction;
}

int PartSolution::reduceCols() {
    int totalColReduction = 0;

    // Reduce each column.
    for (unsigned int colNum = 0; colNum < costMatrix->getNodeCount(); colNum++) {
        int currentColMinValue = getMinValueInCol(colNum);
        if (currentColMinValue != 0) {
            totalColReduction += currentColMinValue;
            // Reduce each node in current column
            for (unsigned int rowNum = 0; rowNum < costMatrix->getNodeCount(); rowNum++) {
                int currentCostBetweenNodes = costMatrix->getCost(rowNum, colNum);
                if (currentCostBetweenNodes != INFINITE_COST) {
                    costMatrix->setCost(rowNum,
                                        colNum,
                                        currentCostBetweenNodes - currentColMinValue);
                }
            }
        }
    }
    return totalColReduction;
}

void PartSolution::prohibitBacktrack(unsigned int sourceNode, unsigned int targetNode) {
    for (unsigned int i = 0; i < costMatrix->getNodeCount(); i++) {
        costMatrix->setCost(sourceNode, i, INFINITE_COST); // Prohibit travel from previous to any
        costMatrix->setCost(i, targetNode, INFINITE_COST); // Prohibit travel from any to current
    }
    // Prohibit travel from current to previous
    costMatrix->setCost(targetNode, sourceNode, INFINITE_COST);
}

string PartSolution::toString() {
    stringstream os;
    os << costMatrix->toString() << "\n";
    os << "Route: " << route->toString(false);
    os << endl;
    return os.str();
}



