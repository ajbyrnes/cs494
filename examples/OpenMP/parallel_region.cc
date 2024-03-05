#include <iostream>
#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        
        printf("Thread %d starting...\n", tid);
        // std::cout << "Thread " << tid << "starting..." << std::endl;
    
        #pragma omp barrier

        printf("Hello from thread %d\n", tid);
        // std::cout << "Hello from thread " << tid << std::endl;

        #pragma omp barrier

        printf("Thread %d done\n", tid);
        // std::cout << "Thread " << tid << " done" << std::endl;
    }

    return 0;
}