#ifndef SRC_STOPWATCH_H
#define SRC_STOPWATCH_H

#include <chrono>
#include <string>
#include <vector>

using namespace std;

typedef std::ratio<1l, 1000000000000l> pico;
typedef chrono::duration<long long, pico> picoseconds;

class Stopwatch {
public:
    Stopwatch();

    chrono::system_clock::time_point start();

    chrono::system_clock::time_point stop();

    unsigned long long getSeconds();

    unsigned long long getMillis();

    unsigned long long getMicros();

    unsigned long long getNanos();

    unsigned long long getPicos();

    double getTimeAsDouble();

    string getScaledTimeString();

protected:
    chrono::high_resolution_clock::time_point endTime;
    chrono::high_resolution_clock::time_point startTime;
};


#endif //SRC_STOPWATCH_H
