#include "Tester.h"

Tester *Tester::setTestedFunc(std::function<void(TestEnv & testEnv)> cb) {
    testedFunc = cb;
    return this;
}

Tester *Tester::beforeEach(std::function<void(TestEnv & testEnv)> cb) {
    beforeEachFunc = cb;
    return this;
}

Tester *Tester::afterEach(std::function<void(TestEnv & testEnv)> cb) {
    afterEachFunc = cb;
    return this;
}

Tester *Tester::afterSameDataSet(std::function<void(TestEnv & testEnv)> cb) {
    afterSameDataSetFunc = cb;
    return this;
}

Tester *Tester::setSameNodeCountRepeats(int i) {
    sameNodeCountRepeats = i;
    return this;
}

double Tester::measureTestedFuncOnce() {
    beforeEachFunc(testEnv);
    Stopwatch stopwatch;
    stopwatch.start();
    if (testedFunc != NULL) {
        testedFunc(testEnv);
    }
    stopwatch.stop();

    afterEachFunc(testEnv);
    return stopwatch.getTimeAsDouble();
}

double Tester::runSingleData() {
    double allRepeatsDuration = 0;
    for (int i = 0; i < sameNodeCountRepeats; i++) {
        allRepeatsDuration += measureTestedFuncOnce();
    }
    double averageTime = allRepeatsDuration / sameNodeCountRepeats;
    std::cout << log << "NodeCount:" << testEnv.nodeCount << " AvgTime:" << averageTime << std::endl;
    afterSameDataSetFunc(testEnv);
    return averageTime;
}

std::vector<Tester::TestResult> Tester::runAll() {
    auto testResults = std::vector<Tester::TestResult>();

    for (int currentNodeCount = testEnv.startNodeCount;
         currentNodeCount <= testEnv.finishNodeCount;
         currentNodeCount++) {
        testEnv.nodeCount = currentNodeCount;
        TestResult result = TestResult(testEnv);
        result.time = runSingleData();
        testResults.push_back(result);
    }
    lastResults = testResults;
    return testResults;
}

Tester *Tester::writeLastTestResultToFile(std::string filePath) {
    std::ofstream outFile;
    outFile.open(filePath);
    outFile << "Node count, Time" << std::endl;
    for (auto testResult : lastResults) {
        outFile << testResult.nodeCount << ",";
        outFile << testResult.time;
        outFile << std::endl;
    }
    outFile.close();
    return this;
}
