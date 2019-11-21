#ifndef SRC_GENERICCLI_H
#define SRC_GENERICCLI_H

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <map>

using namespace std;

class GenericCli {
public:
    virtual void run() = 0;

protected:
    GenericCli();

    virtual void loadMenuOptions() = 0;

    map<int, string> menuOptions;

    enum genericChoices {
        CHOICE_EXIT = 0
    };

    string interfaceHeader = "GENERIC CLI";

    virtual void runChoice(int choiceNumber) = 0;

    // User input
    int userChoice = -1;

    int getNumberInput(string promptMessage = "");

    string getStringInput(string promptMessage = "");

    void pressAnyKeyToContinue();

    // Other
    void displayNumberChoices();

    void clearConsole();

    void displayPrompt(string promptMessage = "");

    void displayHeader();

    void displayVerticalSpace(int height = 1);

    void invalidChoice();

};


#endif //SRC_GENERICCLI_H
