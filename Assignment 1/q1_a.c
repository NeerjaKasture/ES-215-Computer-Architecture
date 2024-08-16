#include <stdio.h>
#include <time.h>

unsigned long long fibonacci_recurse(unsigned long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recurse(n - 1) + fibonacci_recurse(n - 2);
}

void print_fibonacci_recurse(int n) {
    if (n == 0) {
        printf("%lld ", fibonacci_recurse(n));
    } else {
        print_fibonacci_recurse(n - 1); 
        printf("%lld ", fibonacci_recurse(n));  
    }
}

int main() {
    struct timespec start, end;
    double elapsed;

    timespec_get(&start, TIME_UTC);
    print_fibonacci_recurse(49);
    timespec_get(&end, TIME_UTC);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nRecursion time: %.9f seconds\n", elapsed);

    return 0;
}




