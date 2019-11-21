#include "GenericCli.h"

using namespace std;

int GenericCli::getNumberInput(string promptMessage) {
    displayPrompt(promptMessage);
    int choice;
    cin >> choice;
    return choice;
}

string GenericCli::getStringInput(string promptMessage) {
    displayPrompt(promptMessage);
    string userInput;
    cin >> userInput;
    return userInput;
}

void GenericCli::pressAnyKeyToContinue() {
    cout << "\nPress any key to continue...";
    (void) _getch();
}

void GenericCli::clearConsole() {
    system("CLS");
}

void GenericCli::displayPrompt(string promptMessage) {
    if (promptMessage.length()) {
        cout << promptMessage << endl;
    }
    cout << ">>> ";
}

void GenericCli::displayHeader() {
    cout << "\n" << "######## " << interfaceHeader << " ########" << endl;
}

void GenericCli::displayVerticalSpace(int height) {
    for (int i = 0; i < height; i++) {
        cout << endl;
    }
}

GenericCli::GenericCli() {
    menuOptions = map<int, string>();
}

void GenericCli::displayNumberChoices() {
    for (unsigned int choiceNum = 0; choiceNum < menuOptions.size(); choiceNum++) {
        cout << choiceNum << ". " << menuOptions[choiceNum] << "\n";
    }
    cout << flush;
}

void GenericCli::invalidChoice() {
    cout << "Invalid choice! " << flush;
    pressAnyKeyToContinue();
}

