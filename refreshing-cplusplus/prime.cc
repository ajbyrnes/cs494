/*
Amy Byrnes
C++ and Make
1/23/24
I certify that this is my work, and, where appropriate, an extension of the starter code provided for this assignment.
*/

#include <iostream>
#include <cmath>
#include <chrono>

bool isPrime (int number) {
    if (number <= 1) return false;

    for (int i = 2; i <= sqrt(number); i++) {
        if (!(number % i)) return false;
    }

    return true;
}

int main(int argc, char *argv[]) {
    int range_start = 0, range_end = 0;

    std::cout << "Enter start of range: ";
    std::cin >> range_start;
    std::cout << "Enter end of range: ";
    std::cin >> range_end;

    std::chrono::high_resolution_clock::time_point time_start = std::chrono::high_resolution_clock::now();

    for (int i = range_start; i <= range_end; i++) {  
        bool result = isPrime(i);
        if (result) std::cout << i << " is a prime number" << std::endl;
    }

    std::chrono::high_resolution_clock::time_point time_end = std::chrono::high_resolution_clock::now();

    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start);
    
    std::cout << "Time to find primes between " << range_start << " and " << range_end << " was " << duration.count() << " milliseconds" << std::endl;

    return 0;   
}