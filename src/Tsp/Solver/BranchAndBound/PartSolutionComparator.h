#ifndef SRC_PARTSOLUTIONCOMPARATOR_H
#define SRC_PARTSOLUTIONCOMPARATOR_H

#include "PartSolution.h"

class PartSolutionComparator {
public:
    bool operator()(const shared_ptr<PartSolution> &left,
                    const shared_ptr<PartSolution> &right);

    bool operator()(const PartSolution &left,
                    const PartSolution &right);
};

#endif // SRC_PARTSOLUTIONCOMPARATOR_H
