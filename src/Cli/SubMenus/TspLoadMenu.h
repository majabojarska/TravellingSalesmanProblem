
#ifndef SRC_TSPLOADMENU_H
#define SRC_TSPLOADMENU_H

#include "../GenericTspCli.h"


class TspLoadMenu : public GenericTspCli {
public:
    TspLoadMenu();

protected:
    void loadMenuOptions() override;

public:

    void run() override;

    shared_ptr<TSP> getTsp();

protected:
    void runChoice(int choiceNumber) override;

private:
    enum choices {
        CHOICE_RANDOM_SYM = 1,
        CHOICE_RANDOM_ASYM,
        CHOICE_FROM_FILE,
        CHOICE_CLEAR
    };

    shared_ptr<TSP> tsp;
};


#endif //SRC_TSPLOADMENU_H
