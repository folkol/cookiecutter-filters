#include <stdio.h>

int main(void) {
    char buf[1024];
    while (fgets(buf, sizeof buf, stdin))
        ;
}

