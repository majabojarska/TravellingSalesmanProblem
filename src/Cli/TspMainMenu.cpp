
#include "TspMainMenu.h"


TspMainMenu::TspMainMenu() : GenericTspCli() {
    interfaceHeader = "TRAVELLING SALESMAN PROBLEM";
    loadMenuOptions();
}

void TspMainMenu::loadMenuOptions() {
    menuOptions[CHOICE_LOAD] = "Load";
    menuOptions[CHOICE_SOLVE] = "Solve";
    menuOptions[CHOICE_PRINT_TSP] = "Print TSP";
    menuOptions[CHOICE_EXIT] = "Exit";
}

void TspMainMenu::run() {
    while (userChoice != CHOICE_EXIT) {
        displayHeader();
        displayNumberChoices();
        cout << endl;
        userChoice = getNumberInput();
        runChoice(userChoice);
    }
}

void TspMainMenu::runChoice(int choiceNumber) {
    if (choiceNumber == CHOICE_LOAD) {
        TspLoadMenu tspLoadMenu;
        tspLoadMenu.run();
        this->tsp = tspLoadMenu.getTsp();
    } else if (choiceNumber == CHOICE_SOLVE) {
        TspSolveMenu tspSolveMenu(this->tsp);
        tspSolveMenu.run();
    } else if (choiceNumber == CHOICE_PRINT_TSP) {
        if (tsp) {
            cout << this->tsp->toString() << endl;
        } else {
            cout << "Load a TSP instance first!" << endl;
        }
    } else if (choiceNumber == CHOICE_EXIT) {
        return;
    } else {
        invalidChoice();
    }
}
