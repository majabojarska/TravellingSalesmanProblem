#include "Utils/InputParser.h"
#include "Cli/TspMainMenu.h"
#include "Benchmark/Benchmark.h"

int main(int argc, char **argv) {
    InputParser inputParser(argc, argv);

    if (inputParser.cmdOptionExists("--benchmark")) {
        performAllBenchmarks();
    } else {
        TspMainMenu menu;
        menu.run();
    }
    return 0;
}

