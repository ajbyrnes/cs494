[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/B79KocTe)
# Quiz01 - Exam00 Test Run
You will complete this quiz in two parts within the time allotted.

### Part One (10 Points) Microsoft Forms

We are using the standard Microsoft Forms for all the quizzes in the class. 

You can find the Microsoft Forms portion of the exam at the URL: [https://forms.office.com/r/LLqbNPjZPt](https://forms.office.com/r/LLqbNPjZPt)

### Part Two (15 Points) OpenMP Programming
Given an array of integers, your task is to compute the sum of all the elements in the array using OpenMP. You must ensure that your program can run in parallel to utilize multiple cores for the computation to speed up the process. Your solution should demonstrate a basic understanding of OpenMP directives for parallel regions and reduction operations.

**Requirements**
- Use OpenMP to parallelize the computation.
- Ensure your program handles the summation operation in a thread-safe manner.
- The final output should be the sum of all elements in the array.
- Comment your code to explain the use of OpenMP directives.

**Starter Code**
```c++
#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 1000

int main() {
    int array[ARRAY_SIZE];
    int totalSum = 0;

    // Initialize the array with some values
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i;
    }

    // TODO: Parallelize this loop with OpenMP to compute the sum of array elements
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        totalSum += array[i];
    }

    printf("Total sum is %d\n", totalSum);
    return 0;
}
```

When complete, ensure you have done a `git commit` and `git push` so your results are sent back to GitHub for grading. You do not need to use a **development** branch during quizzes and exams.
