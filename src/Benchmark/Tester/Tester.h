#ifndef SRC_TESTER_H
#define SRC_TESTER_H

#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

#include "../../Utils/Stopwatch.h"

class Tester {
public:
    struct TestEnv {
        int startNodeCount = 0;
        int nodeCount = 0;
        int finishNodeCount = 0;
    };

    struct TestResult : TestEnv {
        TestResult() {};

        TestResult(TestEnv const &t) : TestEnv(t) {};
        double time;
    };

    TestEnv testEnv = TestEnv();

    Tester *setTestedFunc(std::function<void(TestEnv &testEnv)> cb);

    Tester *beforeEach(std::function<void(TestEnv &testEnv)> cb);

    Tester *afterEach(std::function<void(TestEnv &testEnv)> cb);

    Tester *afterSameDataSet(std::function<void(TestEnv &testEnv)> cb);

    Tester *setSameNodeCountRepeats(int i);

    Tester *writeLastTestResultToFile(std::string filePath);

    std::vector<TestResult> runAll();

    std::string log = "";

    int sameNodeCountRepeats = 1;

private:
    std::vector<TestResult> lastResults;

    std::function<void(TestEnv &testEnv)> testedFunc = [](TestEnv &env) {};
    std::function<void(TestEnv &testEnv)> beforeEachFunc = [](TestEnv &env) {};
    std::function<void(TestEnv &testEnv)> afterEachFunc = [](TestEnv &env) {};
    std::function<void(TestEnv &testEnv)> afterSameDataSetFunc = [](TestEnv &env) {};


    double measureTestedFuncOnce();

    double runSingleData();
};


#endif //SRC_TESTER_H
