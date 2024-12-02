#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_i(int times);
unsigned long long fib_r(int times);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <index> <method>\n", argv[0]);
        return 1;
    }
    int index = atoi(argv[1]);
    char fib_method = argv[2][0];

    if (fib_method == 'i') {
        printf("%llu\n", fib_i(index));
    } else if (fib_method == 'r') {
        printf("%llu\n", fib_r(index));
    }

    return 0;
}

unsigned long long fib_i(int times) {
    if (times == 1) {
        return 0;
    }

    if (times == 2) {
        return 1;
    }

    --times;

    unsigned long long prev_1 = 0;
    unsigned long long prev_2 = 1;
    unsigned long long next_term = prev_1 + prev_2;

    for (int ix = 3; ix <= times; ++ix) {
        prev_1 = prev_2;
        prev_2 = next_term;
        next_term = prev_1 + prev_2;
    }

    return next_term;
}

unsigned long long fib_r(int times) {
    if (times == 1) {
        return 0;
    }

    if (times == 2) {
        return 1;
    }

    return fib_r(times - 1) + fib_r(times - 2);
}