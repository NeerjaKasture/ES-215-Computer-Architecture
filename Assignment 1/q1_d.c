#include <stdio.h>
#include <time.h>

void print_fibonacci_loop_memo() {
    unsigned long long fib[50];
    fib[0] = 0;
    fib[1] = 1;
    printf("%lld %lld ",fib[0],fib[1]);
    for (int i = 2; i < 50; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("%lld ",fib[i]);
    }
    printf("\n");
}

int main() {
    struct timespec start, end;
    double elapsed;

    timespec_get(&start, TIME_UTC);
    print_fibonacci_loop_memo();
    timespec_get(&end, TIME_UTC);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nLoop with memoization time: %.9f seconds\n", elapsed);

    return 0;
}
