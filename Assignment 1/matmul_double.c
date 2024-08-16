#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double multiply_matrices(double **a, double **b, double **result,int N) {
    struct timespec start1, end1;

    timespec_get(&start1, TIME_UTC);
    for (int ii = 0; ii < N; ++ii) {
        for (int j = 0; j < N; ++j) {
            result[ii][j] = 0.0;
            for (int k = 0; k < N; ++k) {
                result[ii][j] += a[ii][k] * b[k][j];
            }
        }
    }
    timespec_get(&end1, TIME_UTC);
    double elapsed = (end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1e9;
    return elapsed;
}

int main() {
    struct timespec start, end;
    timespec_get(&start, TIME_UTC);
    int sizes[]={64, 128, 256, 512, 1024};
    double times[5];
    double mult_times[5];
    for(int i=0;i<5;i++){
        struct timespec start_time, end_time;
        timespec_get(&start_time, TIME_UTC);

        int N=sizes[i]; 
        double **a = malloc(N * sizeof(double *));
        double **b = malloc(N * sizeof(double *));
        double **result = malloc(N * sizeof(double *));
        
        for (int j = 0; j < N; j++) {
            a[j] = malloc(N * sizeof(double));
            b[j] = malloc(N * sizeof(double));
            result[j] = malloc(N * sizeof(double));
        }
        

        for(int k = 0; k < N; k++) {
            for (int j = 0; j < N; ++j) {
                a[k][j] = (double)rand() / RAND_MAX;
                b[k][j] = (double)rand() / RAND_MAX;
            }
        }
        
        mult_times[i]=multiply_matrices(a, b, result,N);
        timespec_get(&end_time, TIME_UTC);
        times[i]= (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;;
        for (int j = 0; j < N; ++j) {
            free(a[j]);
            free(b[j]);
            free(result[j]);
        }
        free(a);
        free(b);
        free(result);
    }
    timespec_get(&end, TIME_UTC);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Total time: %.6f seconds\n", elapsed);
    printf("Matrix size Time for iteration Time for multiplication");
    for(int i=0;i<5;i++){
        printf("\n %d %.6f %.6f",sizes[i],times[i],mult_times[i]);
    }
    return 0;
}
