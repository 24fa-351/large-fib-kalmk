#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_i(int times);
unsigned long long fib_r(int times);

int main(int argc, char *argv[]) {
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

    unsigned long long t1 = 0;
    unsigned long long t2 = 1;
    unsigned long long next_term = t1 + t2;

    for (int ix = 3; ix <= times; ++ix) {
        t1 = t2;
        t2 = next_term;
        next_term = t1 + t2;
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