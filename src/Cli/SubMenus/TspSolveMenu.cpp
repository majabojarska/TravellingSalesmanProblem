
#include "TspSolveMenu.h"

using namespace solver;

TspSolveMenu::TspSolveMenu(const shared_ptr<TSP> &tsp) : GenericTspCli() {
    this->tsp = tsp;
    interfaceHeader = string("SOLVE");
    loadMenuOptions();
    solutionRoute.reset();

    if (!isTspValid()) {
        cout << "Load a TSP instance first." << endl;
        userChoice = CHOICE_EXIT;
    }
}

void TspSolveMenu::run() {
    while (userChoice != CHOICE_EXIT) {
        displayHeader();
        displayNumberChoices();
        cout << endl;
        userChoice = getNumberInput();
        runChoice(userChoice);
    }
}

void TspSolveMenu::runChoice(int choiceNumber) {
    if (choiceNumber == CHOICE_BF) {
        solver = static_pointer_cast<GenericSolver>(make_shared<BruteForce>());
    } else if (choiceNumber == CHOICE_DP) {
        solver = static_pointer_cast<GenericSolver>(make_shared<DynamicProg>());
    } else if (choiceNumber == CHOICE_BNB) {
        solver = static_pointer_cast<GenericSolver>(make_shared<BranchAndBound>());
    } else if (choiceNumber == CHOICE_EXIT) {
        return;
    } else {
        invalidChoice();
    }

    if (solver) {
        timeUtils.start();
        solver->setTsp(tsp);
        solutionRoute = solver->getSolution();
        timeUtils.stop();

        solver.reset();

        printSolutionTime();
        printSolutionCost();
        if (tsp->getNodeCount() < 20) {
            printSolutionRoute();
        }
    }
}

void TspSolveMenu::loadMenuOptions() {
    menuOptions[CHOICE_BF] = "Brute force";
    menuOptions[CHOICE_DP] = "Dynamic programming (Held & Karp)";
    menuOptions[CHOICE_BNB] = "Branch and bound";
    menuOptions[CHOICE_EXIT] = "Exit";
}

bool TspSolveMenu::isTspValid() {
    if (tsp) {
        return true;
    }
    return false;
}

void TspSolveMenu::printSolutionTime() {
    cout << "Execution time: ";
    cout << timeUtils.getScaledTimeString() << endl;
}

void TspSolveMenu::printSolutionCost() {
    cout << "Solution cost: " << tsp->getCycleCost(solutionRoute) << endl;
}

void TspSolveMenu::printSolutionRoute() {
    cout << "Solution route: " << solutionRoute->toString(true);
}
