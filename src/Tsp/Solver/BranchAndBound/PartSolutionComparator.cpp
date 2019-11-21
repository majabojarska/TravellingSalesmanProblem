#include "PartSolutionComparator.h"

bool PartSolutionComparator::operator()(const shared_ptr<PartSolution> &left,
                                        const shared_ptr<PartSolution> &right) {
    return left->lowerBound > right->lowerBound;
}

bool PartSolutionComparator::operator()(const PartSolution &left,
                                        const PartSolution &right) {
    return left.lowerBound > right.lowerBound;
}
