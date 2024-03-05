#include <iostream>
#include <chrono>

int main() {
    auto duration = std::chrono::hours(1);

    // Convert from hours to minutes
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);

    // Convert from hours to seconds
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);

    // Convert from hours to milliseconds
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

    // Convert from hours to microseconds
    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);

    // Convert from hours to nanoseconds
    auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

    std::cout << "1 hour is equivalent to:\n";
    std::cout << minutes.count() << " minutes\n";
    std::cout << seconds.count() << " seconds\n";
    std::cout << milliseconds.count() << " milliseconds\n";
    std::cout << microseconds.count() << " microseconds\n";
    std::cout << nanoseconds.count() << " nanoseconds" << std::endl;
    
    return 0;
}