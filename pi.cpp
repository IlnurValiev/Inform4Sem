#include <omp.h>
#include <stdio.h>
#include <cmath>

int N = 100000;
double pi = 0;

int main() {
    double s;
    double time1 = omp_get_wtime();
    for(int i = 0; i < N; i++) {
        s = (1/(double)N)*sqrt(1-pow((double)i/(double)N, 2));
        pi += 4*s;
    }
    double time2 = omp_get_wtime();
    double time = time2-time1;
    printf("1 proc: pi = %2f; time = %2f sec\n", pi, time);
    
    pi = 0;
    double *S;
    int num = 4;
    omp_set_num_threads(num);

    S = new double[num];
  
    time1 = omp_get_wtime();
    #pragma omp parallel for
        for(int i = 0; i < N; i++) {
            S[omp_get_thread_num()] += (1/(double)N)*sqrt(1-pow((double)i/(double)N, 2));
        }
    for(int i = 0; i < num; i++) {
        pi += 4*S[i];
        S[i] = 0;
    }
    time2 = omp_get_wtime();
    time = time2-time1;
    printf("%d proc par for: pi = %2f; time = %2f sec\n", num, pi, time);

    pi = 0;
    time1 = omp_get_wtime();
    #pragma omp parallel 
    {
        int n = omp_get_thread_num();
        for(int i = n*N/num; i < (n+1)*N/num; i++)
            S[n] += (1/(double)N)*sqrt(1-pow((double)i/(double)N, 2));
    }
    for(int i = 0; i < num; i++) 
        pi += 4*S[i];
    time2 = omp_get_wtime();
    time = time2-time1;
    printf("%d proc par: pi = %2f; time = %2f sec\n", num, pi, time);
    
}