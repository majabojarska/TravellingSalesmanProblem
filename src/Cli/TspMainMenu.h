
#ifndef SRC_TSPMAINMENU_H
#define SRC_TSPMAINMENU_H

#include "GenericTspCli.h"
#include "SubMenus/TspLoadMenu.h"
#include "SubMenus/TspSolveMenu.h"


class TspMainMenu : public GenericTspCli {

public:
    TspMainMenu();

    void run() override;

protected:
    void loadMenuOptions() override;

    void runChoice(int choiceNumber) override;

private:
    enum choices {
        CHOICE_LOAD = 1,
        CHOICE_SOLVE,
        CHOICE_PRINT_TSP
    };

    shared_ptr<TSP> tsp;
};


#endif //SRC_TSPMAINMENU_H
