#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char generateRandomChar() {
    static const char charset[] = "0123456789ABCDEF";
    return charset[rand() % (sizeof(charset) - 1)];
}

void generateRandomString(char *string) {
    int length = 3 + rand() % 8; // Random length between 3 and 10 characters
    for (int i = 0; i < length; ++i) {
        string[i] = generateRandomChar();
    }
    string[length] = '\0';
}

int determineHighestBase(const char *alphanumericString) {
    int highestBase = 0;
    for (int i = 0; alphanumericString[i] != '\0'; ++i) {
        int currentBase = (isdigit(alphanumericString[i])) ? (alphanumericString[i] - '0') : (alphanumericString[i] - 'A' + 10);
        highestBase = (currentBase > highestBase) ? currentBase : highestBase;
    }
    return highestBase + 1;
}

int main() {
    srand(time(NULL));

    int baseCounts[16] = {0}; // Count for each possible base

    for (int i = 0; i < 50; ++i) {
        char randomString[11];
        generateRandomString(randomString);
        int highestBase = determineHighestBase(randomString);
        ++baseCounts[highestBase];
        printf("Random String: %s | Highest Base: %d\n", randomString, highestBase);
    }

    // Display count of strings belonging to each highest base
    for (int i = 0; i < 16; ++i) {
        printf("Strings with Highest Base %d: %d\n", i, baseCounts[i]);
    }

    return 0;
}
