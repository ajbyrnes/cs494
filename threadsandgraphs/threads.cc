/*
    Amy J. Byrnes
    CS494 - Scalability of Threads in Quicksort
    02-08-2024

    I certify that this is my work and, where appropriate, an extension of the starter code provided for the assignment.
*/

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <fstream>
#include <cmath>

// Function to perform quick sort (students should not modify this)
void quickSort(std::vector<int>& values, int left, int right, int depth = 0);
int partition(std::vector<int>& values, int left, int right);

int main(int argc, char *argv[]) 
{
    const int SIZE = 500000;
    std::vector<int> originalValues(SIZE);

    // Fill the vector with random integers
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, SIZE);
    for (int& value : originalValues) {
        value = distrib(gen);
    }// End of For

    int maxThreads = std::thread::hardware_concurrency();
    std::cout << "Maximum Threads: " << maxThreads << std::endl;

    // Open file for writing
    std::ofstream dataFile("threads.dat");
    dataFile << "Run,Threads,Time (seconds)\n";

    // Run experiments with different thread counts (students add timing and data collection code in loop)
    for (int currentThreads = 1; currentThreads <= std::max(1, maxThreads); currentThreads *= 2) {
        int depth = std::max(1, int(log2(currentThreads)));
        std::cout << "Testing with " << currentThreads << " threads (Depth: " << depth << ")\n";

        for (int run = 1; run <= 10; run++) {
            // Good idea to run a number of experiments with exactly the same data
            std::vector<int> values = originalValues;

            std::cout << "Run " << run << ": ";
            auto startTime = std::chrono::high_resolution_clock::now();

            // Perform quick sort (students should not modify this)
            quickSort(values, 0, SIZE - 1, depth);

            auto endTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = endTime - startTime;

            // Students write code here to collect and process timing data
            // For example: Store timing data in a data structure or file
            dataFile << run << "," << currentThreads << "," << duration.count() << "\n";
            
            std::cout << duration.count() << " seconds\n";
        }

        // std::cout << duration.count() << " seconds\n";
    }// End of FOR looping over thread pools 

    return 0;
}// End of MAIN

// Quick Sort Algorithm (students should not modify this)
void quickSort(std::vector<int>& values, int left, int right, int depth) {
    if (left < right) {
        int pivotIndex = partition(values, left, right);

        if (depth > 0) {
            std::thread leftThread(quickSort, std::ref(values), left, pivotIndex - 1, depth - 1);
            quickSort(values, pivotIndex + 1, right, depth - 1);
            leftThread.join();
        } else {
            quickSort(values, left, pivotIndex - 1, 0);
            quickSort(values, pivotIndex + 1, right, 0);
        }// End of IF / ELSE
    }// End of IF
}// End of quickSort()

// Partition function for Quick Sort (students should not modify this)
int partition(std::vector<int>& values, int left, int right) {
    int pivot = values[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (values[j] < pivot) {
            i++;
            std::swap(values[i], values[j]);
        }// End of IF
    }// End of FOR
    std::swap(values[i + 1], values[right]);
    return (i + 1);
}// End of partition()
