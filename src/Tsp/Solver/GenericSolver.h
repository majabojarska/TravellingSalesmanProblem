#ifndef SRC_GENERICSOLVER_H
#define SRC_GENERICSOLVER_H

#include <memory>
#include <stdexcept>

#include "../Route.h"
#include "../TSP.h"
#include "../../Utils/PrintUtils.h"

namespace solver {

    class GenericSolver {
    public:
        virtual shared_ptr<Route> getSolution() = 0;

        virtual void setTsp(const shared_ptr<TSP> &tsp) = 0;

    protected:
        shared_ptr<TSP> tsp = nullptr;
    };

}

#endif //SRC_GENERICSOLVER_H
