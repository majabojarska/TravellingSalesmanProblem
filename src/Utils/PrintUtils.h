
#ifndef SRC_PRINTUTILS_H
#define SRC_PRINTUTILS_H

#include <iostream>

using namespace std;

#define USEDEBUG

#ifdef USEDEBUG
#define Debug(x) std::cout << x
#else
#define Debug(x)
#endif

enum AlignDir {
    LEFT,
    CENTER,
    RIGHT
};

namespace utils {

    class PrintUtils {
        static void printAligned(string content, short targetLength, char paddingChar = ' ', short alignDir = CENTER);

        static void printAligned(int content, short targetLength, char paddingChar = ' ', short alignDir = CENTER);
    };

}

#endif //SRC_PRINTUTILS_H
