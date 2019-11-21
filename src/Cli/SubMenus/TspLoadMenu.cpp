
#include "TspLoadMenu.h"


TspLoadMenu::TspLoadMenu() : GenericTspCli() {
    this->tsp = nullptr;
    interfaceHeader = "LOAD";
    loadMenuOptions();
}

void TspLoadMenu::run() {
    displayHeader();
    displayNumberChoices();
    cout << endl;
    userChoice = getNumberInput();
    runChoice(userChoice);
}

void TspLoadMenu::runChoice(int choiceNumber) {
    if (choiceNumber == CHOICE_EXIT) {
        return;
    } else if (choiceNumber == CHOICE_RANDOM_SYM) {
        int nodeCount = getNumberInput("Enter node count");
        tsp = make_shared<TSP>(TSP::getRandomSymmetric(nodeCount));
    } else if (choiceNumber == CHOICE_RANDOM_ASYM) {
        int nodeCount = getNumberInput("Enter node count");
        tsp = make_shared<TSP>(TSP::getRandomAsymmetric(nodeCount));
    } else if (choiceNumber == CHOICE_FROM_FILE) {
        tsp = make_shared<TSP>(TSP::loadFromFile(getStringInput("Enter path to file")));
    } else if (choiceNumber == CHOICE_CLEAR) {

    } else {
        invalidChoice();
    }
}

void TspLoadMenu::loadMenuOptions() {
    menuOptions[CHOICE_RANDOM_ASYM] = "Generate random asymmetric TSP instance";
    menuOptions[CHOICE_RANDOM_SYM] = "Generate random symmetric TSP instance";
    menuOptions[CHOICE_FROM_FILE] = "Load instance from file";
    menuOptions[CHOICE_CLEAR] = "Clear instance";
    menuOptions[CHOICE_EXIT] = "Exit";
}

shared_ptr<TSP> TspLoadMenu::getTsp() {
    return this->tsp;
}
