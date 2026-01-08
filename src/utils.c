#include <stdio.h>
#include <string.h>
#include "utils.h"

void readString(const char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}

int readInt(const char* prompt, int min, int max) {
    int value;
    do {
        printf("%s", prompt);
        scanf("%d", &value);
        while (getchar() != '\n');
    } while (value < min || value > max);
    return value;
}
