#include "Benchmark.h"

void performBenchmark(shared_ptr<solver::GenericSolver> tspSolver,
                      std::string benchmarkName,
                      int startNodeCount,
                      int finishNodeCount,
                      int sameNodeCountRepeats) {
    shared_ptr<TSP> tsp = nullptr;
    auto tester = make_shared<Tester>();

    tester->log = benchmarkName + ": ";
    tester->testEnv.startNodeCount = startNodeCount;
    tester->testEnv.finishNodeCount = finishNodeCount;

    tester->setSameNodeCountRepeats(sameNodeCountRepeats)
            ->beforeEach([&tspSolver, &tsp](Tester::TestEnv &env) {
                tsp = make_shared<TSP>(TSP::getRandomSymmetric(env.nodeCount));
                tspSolver->setTsp(tsp);
            })
            ->setTestedFunc([&tspSolver, &tsp](Tester::TestEnv &env) {
                tspSolver->getSolution();
            })
            ->afterSameDataSet([](Tester::TestEnv &env) {
                env.nodeCount++;
            });
    tester->runAll();
    tester->writeLastTestResultToFile(
            "benchmark/" +
            benchmarkName + "_" +
            to_string(tester->testEnv.startNodeCount) + "-" +
            to_string(tester->testEnv.finishNodeCount) + "_Rep" +
            to_string(tester->sameNodeCountRepeats) + ".csv"
    );
}

void performAllBenchmarks() {
    performBenchmark(make_shared<solver::BruteForce>(), "BruteForce", 4, 8, 1000);
    performBenchmark(make_shared<solver::BruteForce>(), "BruteForce", 9, 11, 100);
    performBenchmark(make_shared<solver::BruteForce>(), "BruteForce", 12, 13, 10);
//    performBenchmark(make_shared<solver::BranchAndBound>(), "BranchAndBound");
    performBenchmark(make_shared<solver::DynamicProg>(), "DynamicProg", 4, 16, 1000);
    performBenchmark(make_shared<solver::DynamicProg>(), "DynamicProg", 17, 20, 100);
    performBenchmark(make_shared<solver::DynamicProg>(), "DynamicProg", 21, 24, 10);
}