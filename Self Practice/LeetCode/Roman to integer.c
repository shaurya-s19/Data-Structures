#include <stdio.h>
#include <string.h>

typedef struct roman_numerals {
    char* numeral;
    int value;
} rn;

int romanToInt(char* s) {
    rn roman_numerals[] = {
        {"M", 1000},
        {"CM", 900},
        {"D", 500},
        {"CD", 400},
        {"C", 100},
        {"XC", 90},
        {"L", 50},
        {"XL", 40},
        {"X", 10},
        {"IX", 9},
        {"V", 5},
        {"IV", 4},
        {"I", 1}
    };

    int length_roman_numerals = sizeof(roman_numerals) / sizeof(roman_numerals[0]);
    int num = 0;
    int i = 0;

    while (s[i] != '\0') {
        int matched = 0;
        for (int j = 0; j < length_roman_numerals; j++) {
            int len = strlen(roman_numerals[j].numeral);
            if (strncmp(&s[i], roman_numerals[j].numeral, len) == 0) {
                num += roman_numerals[j].value;
                i += len; // Move index forward by the length of the matched numeral
                matched = 1;
                break; // Exit the for loop after a match is found
            }
        }
        if (!matched) {
            // Handle unexpected characters (for robustness)
            return -1; // or some error value
        }
    }

    return num;
}

int main() {
    int val = romanToInt("III");
    printf("%d\n", val);
    return 0;
}

