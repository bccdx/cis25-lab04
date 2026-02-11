# Danna Xu - All Parts

# Lab 4: Pointers and Dynamic Memory

## Objective: 
The goal of this lab is to gain hands-on experience with pointers. You will practice using the address-of and indirection operators, passing pointers to functions to modify variables (pass-by-reference), and using new and delete to manage memory dynamically.

This lab is meant to be completed during class in teams of up to 4 people, but may be completed individually.

# Part 1: Warm-up & Code Analysis (10 points)
Before you write any new code, analyze the following C++ program. Predict its exact output and write down your reasoning. This exercise is crucial for understanding how pointers affect variables inside and outside of functions.

```cpp
#include <iostream>

void processData(int val, int* ptr) {
    val += 10;
    *ptr += 10;
}

int main() {
    int alpha = 20;
    int beta = 20;

    std::cout << "Before function call:" << std::endl;
    std::cout << "alpha = " << alpha << std::endl;
    std::cout << "beta = " << beta << std::endl;

    processData(alpha, &beta);

    std::cout << "\nAfter function call:" << std::endl;
    std::cout << "alpha = " << alpha << std::endl;
    std::cout << "beta = " << beta << std::endl;

    return 0;
}
```

## Your Task:
On a separate document (e.g., a Google Doc or a text file), answer the following questions:
- The processData function takes two parameters: int val and int* ptr. Which of these is passed by value, and which is passed by reference?
- What will be the final value of alpha printed by the program? Why doesn't it change to 30?
- What will be the final value of beta printed by the program? Why does its value change?


# Part 2: Finding Min and Max with Pointers (10 points)

## Objective:
Write a single function that finds both the minimum and maximum values in an array. Since a function can only return one value, you will use pointers to pass two variables by reference, allowing the function to modify them directly.

## Requirements:
Create a new C++ project named MinMaxFinder.

In your main function, create an integer array with at least 10 unsorted values. 

### For example:
```cpp
int numbers[] = {23, 5, 67, -2, 45, 87, 1, 99, 34, -10};
```
Also in main, declare two integer variables, min and max, and initialize them both to the first element of the array.

Write a void function with the following signature:
```cpp
void findMinAndMax(const int arr[], int size, int* min, int* max)
```
This function should loop through the array (starting from the second element, index 1).

If it finds an element smaller than the value pointed to by min, it should update the value at the min pointer.

If it finds an element larger than the value pointed to by max, it should update the value at the max pointer.

From main, call findMinAndMax. You will need to pass the array, its size, and the memory addresses of your min and max variables.

After the function call, print the final values of min and max.

### Example Output:
```
The minimum value is: -10
The maximum value is: 99
```

# Part 3: Dynamic Test Score Averager (20 points)

## Objective: 
Write a program that asks the user how many test scores they want to enter, dynamically allocates an array of that size, sorts the scores, and calculates the average. This exercise combines pointers, dynamic memory allocation, and functions.

## Requirements:
Create a new C++ project named DynamicGrades.

Ask the user how many test scores they want to process.

Dynamically allocate a double array of the size entered by the user. Use a pointer to hold the address of this new array. Include an if statement to check if the user entered a positive number for the size.

Write a function void getScores(double* arr, int size) that prompts the user to enter each score and stores them in the dynamically allocated array. Include input validation to ensure the scores are not negative.

Write a function void sortScores(double* arr, int size) that sorts the array in ascending order. If you're unsure about how to do this, I will do a demo in class, or you can look up the "bubble sort" algorithm and implement it.

Write a function double calculateAverage(const double* arr, int size) that calculates and returns the average of the scores.

## From main:
- Call getScores to fill the array.
- Call sortScores to sort it.
- Call calculateAverage to get the average.
- Display the sorted list of scores and the final average, formatted to two decimal places.
- **CRITICAL:** At the end of your main function, you must use delete [] to free the dynamically allocated memory and then set the pointer to nullptr.

### Example Output:
```
How many test scores would you like to enter? 4
Enter score 1: 88.5
Enter score 2: 95
Enter score 3: 72.5
Enter score 4: 83

The sorted scores are: 72.50 83.00 88.50 95.00 
The average score is: 84.75
```

# Submission:
When you are finished, please submit the source code for all three parts in a Git repository. Include a README.md file that includes the names of all contributors and what their contribution was.
