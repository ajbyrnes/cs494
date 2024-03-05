/*
Amy Byrnes
Hello World with OpenMP
2/11/24
I certify that this is my work, and, where appropriate, an extension of the starter code provided for this assignment.
*/

#include <omp.h>
#include <stdio.h>

int main() {
    // Set the number of threads
    omp_set_num_threads(4);

    // Parallel region begins here
    #pragma omp parallel
    { 
        int thread_id = omp_get_thread_num();
        printf("Hello, World! from thread #%d\n", thread_id + 1);
    }
}