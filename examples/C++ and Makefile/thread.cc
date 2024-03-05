#include <iostream>
#include <thread>

// Function that simulates work
void do_work() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Work in the child thread is done!" << std::endl;
}

int main() {
    // Create a std::thread object and pass the function to execute
    std::thread worker(do_work);

    // Simulate some work in the main thread
    std::cout << "Main thread is doing some work..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Wait for worker thread to finihs
    worker.join();

    std::cout << "Main thread continues after joining worker thread." << std::endl;

    return 0;
}