#include <iostream>
#include <stdio.h>
#include <omp.h>

int main() {
    int n = 100;
    int sum = 0;

    // Upstream section: compute initial value of sum
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Parallel section: distribute work among threads
    #pragma omp parallel
    {
        int local_sum = 0;
        
        #pragma omp for
        for (int i = 1; i <= n; i++) {
            local_sum += i;
        }

        #pragma omp critical
        sum += local_sum;
    }

    printf("Final sum: %d\n", sum);

    return 0;
}