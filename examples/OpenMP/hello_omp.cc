#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {
    #pragma omp parallel
    { 
        std::cout << "Hello World... from thread " << omp_get_thread_num() << std::endl;
    }

    #pragma omp parallel
    {
        printf("Hello World... from thread %d using printf.\n", omp_get_thread_num());
    }

    return 0;
}