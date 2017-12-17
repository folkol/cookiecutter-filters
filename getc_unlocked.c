#include <stdio.h>

int main(void) {
    char c;
    while (c = getc_unlocked(stdin), c != EOF)
        ;
}

