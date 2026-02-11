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

### Answer:
```
Before function call:
alpha = 20
beta = 20 

After function call:
alpha = 20
beta = 30
```

## Your Task:
On a separate document (e.g., a Google Doc or a text file), answer the following questions:

- The processData function takes two parameters: int val and int* ptr. Which of these is passed by value, and which is passed by reference?
> **Answer:**
>
> The passed by value is int val, which means that the int plugged into val in the function processData is a copy of whatever val is, and the function does its processes on the copy of val.
>
> The passed by reference is int* ptr, which means that the pointer ptr points to the actual memory address of where the int plugged into ptr in processData is stored. The function does its processes on the original data where ptr is pointing and can modify the original because it knows where the original lives.

- What will be the final value of alpha printed by the program? Why doesn't it change to 30?
> **Answer:**
>
> The final value of alpha printed by the program is 20 and not 30 because the function processData uses a copy of the input for val and not the original value.

- What will be the final value of beta printed by the program? Why does its value change?
> **Answer:**
>
> The final value of beta printed by the program is 30 because the function processData uses a pointer that points to the memory address of where beta is stored, therefore when the *ptr value is modified in processData, the actual data stored at ptr's address (i.e. the original data) is modified.