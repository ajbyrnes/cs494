#include <stdio.h>
#include <omp.h>

int main() {
int n = 100;
    int sum = 0;

    // Upstream section: Compute initial value of sum
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Parallel section
    #pragma omp parallel for reduction(+: sum)
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Final sum: %d\n", sum);

    return 0;
}