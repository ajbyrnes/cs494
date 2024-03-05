#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 999999

int main() {
    int array[ARRAY_SIZE];
    int totalSum = 0;

    // Initialize the array with some values
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i;
    }

    // Start timing
    double start_time = omp_get_wtime();

    // Parallelize this loop with OpenMP to compute the sum of array elements
    // parallel - starts parallel region
    // for - starts worksharing region, automatically divides iterations of loop among threads
    // reduction(+: totalSum) - indicates that totalSum should be treated as a private variable
    // within each thread, and then each local totalSum should be added to the shared totalSum
    // when the thread finishes
    #pragma omp parallel for reduction(+: totalSum)
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        totalSum += array[i];
    }

    // End timing
    double end_time = omp_get_wtime();

    printf("Total sum is %d\n", totalSum);
    printf("Time taken for the loop: %f seconds\n", end_time - start_time);
    return 0;
}
