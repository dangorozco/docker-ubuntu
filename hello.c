#include <stdio.h>
#include "hello.h"

int say_hello(void) {
    printf("Hello ARM World!\n");
    return 0;
}

// Optional: main for standalone run
#ifdef BUILD_MAIN
int main(void) {
    return say_hello();
}
#endif