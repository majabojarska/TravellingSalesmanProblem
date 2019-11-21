#include "Route.h"

Route::Route() = default;

Route::Route(const Route &route) {
    this->routeNodes = vector<unsigned int>(route.routeNodes);
}

Route::Route(const shared_ptr<Route> &route) {
    this->routeNodes = vector<unsigned int>(route->routeNodes);
}

Route::Route(unsigned int nodeCount) {
    routeNodes = std::vector<unsigned int>(nodeCount);
    std::iota(routeNodes.begin(), routeNodes.end(), 0);
}

Route::Route(const std::vector<unsigned int> &routeNodes) {
    this->routeNodes = vector<unsigned int>(routeNodes);
}

unsigned int Route::getNodeCount() {
    return routeNodes.size();
}

std::string Route::toString(bool withReturnToStart) {
    std::stringstream os;

    os << '[';
    for (unsigned int i = 0; i < routeNodes.size() - 1; i++) {
        os << routeNodes.at(i);
        os << ", ";
    }
    os << routeNodes.back();
    if (withReturnToStart) {
        os << ", (" << routeNodes.at(0) << ")";
    }
    os << ']';
    return os.str();
}

void Route::swapNodes(unsigned int indexA, unsigned int indexB) {
    if (indexA == indexB) return;
    int temp = routeNodes[indexA];
    routeNodes[indexA] = routeNodes[indexB];
    routeNodes[indexB] = temp;
}

bool Route::equals(const shared_ptr<Route> &route) {
    return this->routeNodes == route->routeNodes;
}

