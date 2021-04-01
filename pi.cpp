#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

int N = 1000000;
double pi = 0;
//измерять время
int main() {
    double s;
    for(int i = 0; i < N; i++) {
        s = (1/(double)N)*sqrt(1-pow((double)i/(double)N, 2));
        pi += 4*s;
    }
    printf("1 proc: pi = %2f\n", pi);
    
    pi = 0;
    double *S;
    int num;
    omp_set_num_threads(3);
    #pragma omp parallel 
    {
        num = omp_get_num_threads();
        //if(omp_get_thread_num() == 0)
        S = new double[omp_get_num_threads()];
    }
  
    #pragma omp parallel for
        for(int i = 0; i < N; i++) {
            S[omp_get_thread_num()] += (1/(double)N)*sqrt(1-pow((double)i/(double)N, 2));

        }

    for(int i = 0; i < num; i++) {
        pi += 4*S[i];
        //printf("%2f\n", S[i]);
    }
    
    printf("1 proc par: pi = %2f\n", pi);

    



}