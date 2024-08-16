#include <stdio.h>
#include <time.h>

void fibonacci_loop(){
    unsigned long long a=0,b=1,c;
    for(int i=0;i<50;i++){
        printf("%lld ",a);
        c=a+b;
        a=b;
        b=c;
    }
}

int main(){

    struct timespec start, end;
    double elapsed;

    timespec_get(&start, TIME_UTC);
    fibonacci_loop();
    timespec_get(&end, TIME_UTC);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("\nLoop time: %.9f seconds\n", elapsed);

    return 0;

}
