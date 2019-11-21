#ifndef SRC_BENCHMARK_H
#define SRC_BENCHMARK_H

#include <memory>
#include <filesystem>

#include "Tester\Tester.h"
#include "../Tsp/TSP.h"
#include "../Tsp/Solver/BruteForce/BruteForce.h"
#include "../Tsp/Solver/BranchAndBound/BranchAndBound.h"
#include "../Tsp/Solver/Dynamic/DynamicProg.h"

void performBenchmark(shared_ptr<solver::GenericSolver> tspSolver,
                      std::string benchmarkName,
                      int startNodeCount = 4,
                      int finishNodeCount = 13,
                      int sameNodeCountRepeats = 100);

void performAllBenchmarks();

#endif //SRC_BENCHMARK_H
