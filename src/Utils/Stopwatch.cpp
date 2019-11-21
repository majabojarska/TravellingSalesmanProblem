
#include "Stopwatch.h"


Stopwatch::Stopwatch() {

}

chrono::system_clock::time_point Stopwatch::start() {
    startTime = chrono::high_resolution_clock::now();
    return startTime;
}

chrono::system_clock::time_point Stopwatch::stop() {
    endTime = chrono::high_resolution_clock::now();
    return endTime;
}

unsigned long long Stopwatch::getSeconds() {
    return chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
}

unsigned long long Stopwatch::getMillis() {
    return chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
}

unsigned long long Stopwatch::getMicros() {
    return chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
}

unsigned long long Stopwatch::getNanos() {
    return chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
}

unsigned long long Stopwatch::getPicos() {
    return chrono::duration_cast<picoseconds>(endTime - startTime).count();
}

double Stopwatch::getTimeAsDouble() {
    return chrono::duration<double>(endTime - startTime).count();
}

string Stopwatch::getScaledTimeString() {
    auto timeNum = getNanos();
    string postfix = "err";

    vector<int> scaleFactors;
    vector<string> postFixVector;

    scaleFactors.push_back(1);
    postFixVector.push_back("ns");

    scaleFactors.push_back(1000);
    postFixVector.push_back("us");

    scaleFactors.push_back(1000);
    postFixVector.push_back("ms");

    scaleFactors.push_back(1000);
    postFixVector.push_back("sec");

    scaleFactors.push_back(60);
    postFixVector.push_back("min");

    int scaleOperationCount = 0;
    do {
        timeNum /= scaleFactors[scaleOperationCount];
        postfix = postFixVector[scaleOperationCount];
        scaleOperationCount++;
    } while (timeNum > 1000);

    return to_string(timeNum) + postfix;
}


