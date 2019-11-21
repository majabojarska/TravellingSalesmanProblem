#include "PrintUtils.h"

using namespace utils;

void PrintUtils::printAligned(string content, short targetLength, char paddingChar, short alignDir) {
    uint16_t contentLen = content.length();
    uint16_t singlePaddingLen = (targetLength - (contentLen + 2)) / 2;
    string paddingString = string(paddingChar, singlePaddingLen * 2);

    if (alignDir == AlignDir::LEFT) {
        cout << paddingString << paddingString;
        cout << ' ' << content << ' ';
    } else if (alignDir == AlignDir::CENTER) {
        cout << paddingString;
        cout << ' ' << content << ' ';
        cout << paddingString;
    } else if (alignDir == AlignDir::RIGHT) {
        cout << ' ' << content << ' ';
        cout << paddingString << paddingString;
    }
    cout << flush;
}

void PrintUtils::printAligned(int content, short targetLength, char paddingChar, short alignDir) {
    printAligned(to_string(content), targetLength, paddingChar, alignDir);
}
