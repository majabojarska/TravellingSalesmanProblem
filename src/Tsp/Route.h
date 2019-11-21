#ifndef SRC_ROUTE_H
#define SRC_ROUTE_H

#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

#include "Constants.h"

using namespace std;

class Route {

public:
    Route();

    explicit Route(unsigned int nodeCount);

    explicit Route(const vector<unsigned int> &routeNodes);

    explicit Route(const shared_ptr<Route> &route);

    Route(const Route &route);

    unsigned int getNodeCount();

    void swapNodes(unsigned int indexA, unsigned int indexB);

    vector<unsigned int> routeNodes;

    std::string toString(bool withReturnToStart = false);

    bool equals(const shared_ptr<Route> &route);
};


#endif //SRC_ROUTE_H
