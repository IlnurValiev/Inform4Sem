//OpenMP - для параллельного прогания на SMP(shared memory proc)

#include <omp.h>
#include <stdio.h>
#define MAX 100000

int a[MAX], b[MAX], c[MAX];

int main() {    
    double time1 = omp_get_wtime();
    #pragma omp parallel for
        for(int i = 0; i < MAX; i++) {
            a[i] = 1;
            b[i] = 2;
            c[i] = a[i]+b[i];
        }
    double time2 = omp_get_wtime();

    double time = time2-time1;

    printf("time 1 = %2f\n", time);

    omp_set_num_threads(2);
    time1 = omp_get_wtime();
    #pragma omp parallel 
    {
        int num = omp_get_thread_num();
        if(num == 0) {
            for(int i = 0; i < MAX; i++)
                a[i] = 1;
        }
        else if(num == 1) {
            for(int i = 0; i < MAX; i++) {
                b[i] = 2;
                c[i] = a[i]+b[i];
            }
        }
    }
    time2 = omp_get_wtime();
    time = time2-time1;
    printf("time 2 = %2f\n", time);

    omp_set_num_threads(3);
    time1 = omp_get_wtime();
    #pragma omp parallel 
    {
        int num = omp_get_thread_num();
        if(num == 0) {
            for(int i = 0; i < MAX; i++)
                a[i] = 1;
        }
        else if(num == 1) {
            for(int i = 0; i < MAX; i++)
                b[i] = 2;
        }
        else if(num == 2) {
            for(int i = 0; i < MAX; i++)
               c[i] = a[i]+b[i];
        }
    }
    time2 = omp_get_wtime();
    time = time2-time1;
    printf("time 3 = %2f\n", time);
    
    #pragma omp barier

    //нормально разделить цикл

}