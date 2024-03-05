#include <thread>
#include <chrono>
#include <bits/stdc++.h>

bool is_prime(unsigned long long n) {
    if (n <= 1) return false;

    for (unsigned long long i = 2; i < sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1;
    }

    // Parse command line argument as n
    // n = end of range to check for primes
    unsigned long long n = strtoull(argv[1], nullptr, 10);

    // Iterate through numbers 2 to n and check if they are prime
    for (unsigned long long i = 2; i <= n; i++) {
        if (is_prime(i)) {
            // Simulate some additional workload
            std::this_thread::sleep_for(std::chrono::nanoseconds(1));
        }
    }
    
    return 0;
}