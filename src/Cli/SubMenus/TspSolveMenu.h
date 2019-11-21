
#ifndef SRC_TSPSOLVEMENU_H
#define SRC_TSPSOLVEMENU_H

#include "../GenericTspCli.h"
#include "../../Tsp/TSP.h"
#include "../../Tsp/Solver/Solvers.h"
#include "../../Utils/Stopwatch.h"

class TspSolveMenu : public GenericTspCli {
public:
    TspSolveMenu(const shared_ptr<TSP> &tsp);

    void run() override;

protected:
    void runChoice(int choiceNumber) override;

    void loadMenuOptions() override;

private:

    enum choices {
        CHOICE_BF = 1,
        CHOICE_BNB,
        CHOICE_DP
    };

    shared_ptr<Route> solutionRoute;
    shared_ptr<solver::GenericSolver> solver;
    shared_ptr<TSP> tsp;
    Stopwatch timeUtils;

    bool isTspValid();

    void printSolutionTime();

    void printSolutionCost();

    void printSolutionRoute();
};


#endif //SRC_TSPSOLVEMENU_H
