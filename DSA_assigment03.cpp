
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int base_cal(char* str) {
    int max = INT_MIN;

    while (*str != '\0') {
        char last_char = str[0];

        if (last_char >= 'A' && last_char <= 'F') {
            int value = (last_char - 'A') + 10;
            if (value > max) {
                max = value;
            }
        } else if (last_char >= '0' && last_char <= '9') {
            int value = (last_char - '0');
            if (value > max) {
                max = value;
            }
        }

        // Move the pointer to the next character in the string
        str++;
    }

    return (max + 1);
}

char integer_to_character(int num) {
    if (num >= 0 && num <= 9) {
        return num + '0';
    } else if (num >= 10 && num <= 15) {
        return ('A' + (num - 10));
    }
    // Handle the case when num is not in the range of 0 to 15.
    return '\0';
}

int main() {
    int length;
    scanf("%d", &length);

    char* str = (char*)malloc((length + 1) * sizeof(char));

    srand((unsigned int)time(NULL)); // Seed the random number generator with current time

    for (int i = 0; i < length; i++) {
        int random_value = rand() % 15;
        int corresponding_character = integer_to_character(random_value);
        str[i] = corresponding_character;
    }

    str[length] = '\0';

    printf("Given string: %s\n", str);

    int base = base_cal(str);

    printf("Base: %d\n", base);

    free(str);

    return 0;
}