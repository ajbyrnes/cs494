#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random seed
    std::srand(std::time(nullptr));

    // Generate a random duration between 1 and 5 seconds
    int sleepDuration = std::rand() % 5 + 1;

    // Get start time
    auto start = std::chrono::high_resolution_clock::now();

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(sleepDuration));

    // Get end time
    auto end = std::chrono::high_resolution_clock::now();
    
    // Report elasped time
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}