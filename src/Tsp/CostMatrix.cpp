#include "CostMatrix.h"

CostMatrix::CostMatrix(unsigned int nodeCount) {
    dataMatrix = vector<vector<int>>(nodeCount);
    for (unsigned int rowNum = 0; rowNum < nodeCount; rowNum++) {
        dataMatrix[rowNum] = vector<int>(nodeCount);
    }
}

CostMatrix::CostMatrix(const shared_ptr<CostMatrix> &inputCostMatrix) {
    this->dataMatrix = vector<vector<int>>(inputCostMatrix->dataMatrix);
}

CostMatrix CostMatrix::getRandom(unsigned int nodeCount, int minCost, int maxCost, bool isSymmetric) {
    CostMatrix newCostMatrix(nodeCount);
    auto randGenerator = UniformRand(minCost, maxCost);

    for (unsigned int rowNum = 0; rowNum < nodeCount; rowNum++) {
        for (unsigned int colNum = 0; colNum < nodeCount; colNum++) {
            if (colNum == rowNum) {
                newCostMatrix.setCost(rowNum, colNum, INFINITE_COST);
            } else {
                if (rowNum > colNum && isSymmetric) {
                    int symmetricCost = newCostMatrix.getCost(colNum,
                                                              rowNum);
                    newCostMatrix.setCost(rowNum, colNum, symmetricCost);
                } else { // Asymmetric
                    newCostMatrix.setCost(rowNum, colNum, randGenerator.getRandomInt());
                }
            }
        }
    }

    return newCostMatrix;
}


CostMatrix CostMatrix::getRandomAsymmetric(unsigned int nodeCount,
                                           int minCost,
                                           int maxCost) {
    return getRandom(nodeCount, minCost, maxCost, false);
}

CostMatrix CostMatrix::getRandomSymmetric(unsigned int nodeCount,
                                          int minCost,
                                          int maxCost) {
    return getRandom(nodeCount, minCost, maxCost, true);
}

CostMatrix CostMatrix::fromTextFile(const string &inputFile) {
    std::ifstream inputStream(inputFile);
    string instanceName = "";
    int nodeCount = 0;

    inputStream >> instanceName;
    inputStream >> nodeCount;

    auto newCostMatrix = CostMatrix(nodeCount);
    newCostMatrix.instanceName = instanceName;

    int cost = 0;
    for (int rowNum = 0; rowNum < nodeCount; rowNum++) {
        for (int colNum = 0; colNum < nodeCount; colNum++) {
            inputStream >> cost;
            newCostMatrix.setCost(rowNum, colNum, cost);
        }
    }

    return newCostMatrix;
}

unsigned int CostMatrix::getCost(unsigned int rowNum, unsigned int colNum) {
    // row = source, column = target
    return dataMatrix[rowNum][colNum];
}

void CostMatrix::setCost(unsigned int rowNum, unsigned int colNum, int cost) {
    // row = source, column = target
    dataMatrix[rowNum][colNum] = cost;
}

unsigned int CostMatrix::getNodeCount() {
    return dataMatrix.size();
}

vector<int> CostMatrix::getRow(unsigned int rowNum) {
    return dataMatrix[rowNum];
}

vector<int> CostMatrix::getCol(unsigned int colNum) {
    vector<int> targetCol;
    for (unsigned int rowNum = 0; rowNum < getNodeCount(); rowNum++) {
        targetCol.push_back(dataMatrix[rowNum][colNum]);
    }
    return targetCol;
}

CostMatrix &CostMatrix::operator=(const CostMatrix &costMatrix) = default;

vector<int> &CostMatrix::operator[](const unsigned int &rowNum) {
    return dataMatrix[rowNum];
}

string CostMatrix::toString() {
    stringstream os;
    // Column numbers
    os << "     ";
    for (unsigned int colNum = 0; colNum < getNodeCount(); colNum++) {
        os << setw(4) << std::right << to_string(colNum);
    }
    os << '\n';
    // Top bar
    os << "      ";
    for (unsigned int colNum = 0; colNum < getNodeCount() * 4; colNum++) { os << '_'; }
    os << '\n';

    // Rows
    for (unsigned int rowNum = 0; rowNum < getNodeCount(); rowNum++) {
        // Row number
        os << setw(4) << rowNum << ' ';
        // Vertical separator
        os << '|';
        // CostMatrix Row
        for (unsigned int colNum = 0; colNum < getNodeCount(); colNum++) {
            int currentCost = this->getCost(rowNum, colNum);
            os << setw(4) << std::right;
            if (currentCost >= 0) {
                os << currentCost;
            } else if (currentCost == INFINITE_COST) {
                os << " X ";
            } else {
                os << "ERR";
            }
        }
        os << endl;
    }
    return os.str();
}

string CostMatrix::getInstanceName() {
    return instanceName;
}


