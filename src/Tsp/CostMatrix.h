#ifndef SRC_COSTMATRIX_H
#define SRC_COSTMATRIX_H

#include <fstream>
#include <iomanip>
#include <memory>
#include <ostream>

#include "../Utils/UniformRand.h"
#include "Constants.h"

using namespace std;

class CostMatrix {
    static const unsigned int COST_STR_SIZE = 4;

public:
    explicit CostMatrix(unsigned int nodeCount);

    explicit CostMatrix(const shared_ptr<CostMatrix> &inputCostMatrix);

    static CostMatrix fromTextFile(const string &inputFile);

    static CostMatrix getRandomAsymmetric(unsigned int nodeCount,
                                          int minCost = 1,
                                          int maxCost = 999);

    static CostMatrix getRandomSymmetric(unsigned int nodeCount,
                                         int minCost = 1,
                                         int maxCost = 999);



    CostMatrix &operator=(const CostMatrix &costMatrix);

    vector<int> &operator[](const unsigned int &rowNum);

    void setCost(unsigned int rowNum,
                 unsigned int colNum,
                 int cost);

    unsigned int getNodeCount();

    unsigned int getCost(unsigned int sourceNodeNum, unsigned int targetNodeNum);

    vector<int> getRow(unsigned int rowNum);

    vector<int> getCol(unsigned int colNum);

    string getInstanceName();

    string toString();

protected:
    vector<vector<int>> dataMatrix; // dataMatrix[row][col]
    string instanceName;

    static CostMatrix getRandom(unsigned int nodeCount,
                                int minCost,
                                int maxCost,
                                bool isSymmetric = true);
};

#endif //SRC_COSTMATRIX_H
