#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[1024];
    while (fread(buf, 1, sizeof buf, stdin))
        ;
}

