#include <stdio.h>
#include <time.h>


unsigned long long memo [50];

unsigned long long fibonacci_memo(unsigned long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
    return memo[n];
}

void print_fibonacci_memo(int n) {
    if (n == 0) {
        printf("%lld ", fibonacci_memo(n));
    } else {
        print_fibonacci_memo(n - 1);  
        printf("%lld ", fibonacci_memo(n));  
    }
}

int main() {
    for (int i = 0; i < 50; ++i) {
        memo[i] = -1;
    }

    struct timespec start, end;
    double elapsed;

    timespec_get(&start, TIME_UTC);
    print_fibonacci_memo(49);
    timespec_get(&end, TIME_UTC);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nRecursion with memoization time: %.9f seconds\n", elapsed);

    return 0;
}
