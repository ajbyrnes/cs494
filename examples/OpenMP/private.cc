#include <stdio.h>
#include <omp.h>

int main() {
    int n = 100;
    int sum = 0;

    // Upstream section: Compute the initial value of the sum
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Parallel section: Create private variables for each thread
    int id, local_sum;
    
    #pragma omp parallel private(id, local_sum)
    {
        id = omp_get_thread_num();
        local_sum = 0;

        #pragma omp for
        for (int i = 1; i <= n; i++) {
            local_sum += i;
        }

        #pragma omp critical
        sum += local_sum;

        printf("Thread %d local sum: %d\n", id, local_sum);
    } 

    printf("Final sum: %d\n", sum);

    return 0;
}