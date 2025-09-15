C - Pointers
get the memory address of a variable with the reference operator &:
#include <stdio.h>
int main() {
  int myAge = 43;
  printf("%d\n", myAge);
  printf("%p\n", &myAge);
  return 0;
}

A pointer is a variable that stores the memory address of another variable as its value.
A pointer variable points to a data type (like int) of the same type, and is created with the * operator.
The address of the variable you are working with is assigned to the pointer:
#include <stdio.h>
int main() {
  int myAge = 43;  // An int variable
  int* ptr = &myAge;  // A pointer variable, with the name ptr, that stores the address of myAge
  // Output the value of myAge (43)
  printf("%d\n", myAge);
  // Output the memory address of myAge (0x7ffe5367e044)
  printf("%p\n", &myAge);
  // Output the memory address of myAge with the pointer (0x7ffe5367e044)
  printf("%p\n", ptr);
  return 0;
}

Example explained
Create a pointer variable with the name ptr, that points to an int variable (myAge). Note that the type of the pointer has to match the type of the variable you're working with (int in our example).
Use the & operator to store the memory address of the myAge variable, and assign it to the pointer.
Now, ptr holds the value of myAge's memory address.

Dereference
In the example above, we used the pointer variable to get the memory address of a variable (used together with the & reference operator).
You can also get the value of the variable the pointer points to, by using the * operator (the dereference operator):
#include <stdio.h>
int main() {
  int myAge = 43;  // An int variable
  int* ptr = &myAge;  // A pointer variable, with the name ptr, that stores the address of myAge
  // Output the value of myAge (43)
  printf("%d\n", myAge);
  // Output the memory address of myAge (0x7ffe5367e044)
  printf("%p\n", &myAge);
  // Output the memory address of myAge with the pointer (0x7ffe5367e044)
  printf("%p\n", ptr);
  return 0;
}


Note that the * sign can be confusing here, as it does two different things in our code:
* When used in declaration (int* ptr), it creates a pointer variable.
* When not used in declaration, it act as a dereference operator.

Good To Know: There are two ways to declare pointer variables in C:
int* myNum;
int *myNum;
Notes on Pointers
Pointers are one of the things that make C stand out from other programming languages, like Python and Java.
They are important in C, because they allow us to manipulate the data in the computer's memory. This can reduce the code and improve the performance. If you are familiar with data structures like lists, trees and graphs, you should know that pointers are especially useful for implementing those. And sometimes you even have to use pointers, for example when working with files and memory management.
But be careful; pointers must be handled with care, since it is possible to damage data stored in other memory addresses.
Pointers & Arrays
You can also use pointers to access arrays.
Print the memory address of each array element:
#include <stdio.h>
int main() {
  int myNumbers[4] = {25, 50, 75, 100};
  int i;
  for (i = 0; i < 4; i++) {
    printf("%p\n", &myNumbers[i]);
  }
  return 0;
}


Sizeof:
#include <stdio.h>
int main() {
  int myInt;
  printf("%zu", sizeof(myInt));
  return 0;
}

#include <stdio.h>
int main() {
  int myNumbers[4] = {25, 50, 75, 100};
  printf("%zu", sizeof(myNumbers));
  return 0;
}
Pointers Related to Arrays

Ok, so what's the relationship between pointers and arrays? Well, in C, the name of an array, is actually a pointer to the first element of the array.
Confused? Let's try to understand this better, and use our "memory address example" above again.
The memory address of the first element is the same as the name of the array:
#include <stdio.h>
int main() {
  int myNumbers[4] = {25, 50, 75, 100};
  // Get the memory address of the myNumbers array
  printf("%p\n", myNumbers);
  // Get the memory address of the first array element
  printf("%p\n", &myNumbers[0]);
  return 0;
}

To access the rest of the elements in myNumbers, you can increment the pointer/array (+1, +2, etc):
#include <stdio.h>
int main() {
  int myNumbers[4] = {25, 50, 75, 100};
  // Get the value of the second element in myNumbers
  printf("%d\n", *(myNumbers + 1));
  // Get the value of the third element in myNumbers
  printf("%d", *(myNumbers + 2));
  return 0;
}

Or loop through it:
#include <stdio.h> 
int main() {
  int myNumbers[4] = {25, 50, 75, 100};
  int *ptr = myNumbers;
  int i;

  for (i = 0; i < 4; i++) {
    printf("%d\n", *(ptr + i));
  }
  return 0;
}

It is also possible to change the value of array elements with pointers:
#include <stdio.h> 
int main() {
  int myNumbers[4] = {25, 50, 75, 100};
  // Change the value of the first element to 13
  *myNumbers = 13;
  // Change the value of the second element to 17
  *(myNumbers +1) = 17;
  // Get the value of the first element
  printf("%d\n", *myNumbers);
  // Get the value of the second element
  printf("%d\n", *(myNumbers + 1));  
    return 0;
}
pointer to a pointer
pointer to a pointer (also called a double pointer) means you're dealing with a pointer that stores the address of another pointer. It's written as type **ptr;.
#include <stdio.h>
int main() {
    int a = 10;
    int *p = &a;      // pointer to int
    int **pp = &p;    // pointer to pointer to int
    printf("Value of a: %d\n", a);          // 10
    printf("Value via *p: %d\n", *p);       // 10
    printf("Value via **pp: %d\n", **pp);   // 10
    printf("Address of a: %p\n", (void*)&a);
    printf("Address stored in p: %p\n", (void*)p);
    printf("Address stored in pp: %p\n", (void*)pp);
    printf("Address of p: %p\n", (void*)&p);
    return 0;
}

In C, malloc stands for memory allocation. It's a function used to dynamically allocate memory on the heap during runtime.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *p;
    p = (int *)malloc(sizeof(int));  // allocate memory for one int
    if (p == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }
    *p = 50;  // assign value to the allocated memory
    printf("Value: %d\n", *p);
    free(p);  // free the memory when done
    return 0;
}

Problem 1: Swap Two Numbers Using Pointers
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

Problem 2: Sum of Array Elements Using Pointer
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 0;
    int *p = arr;

    for (int i = 0; i < 5; i++) {
        sum += *(p + i);  // or p[i]
    }

    printf("Sum = %d\n", sum);
    return 0;
}

Problem 3: Count Vowels in a String Using Pointer#include <stdio.h>

int main() {
    char str[] = "Pointer Example";
    char *p = str;
    int count = 0;

    while (*p) {
        char ch = *p;
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' || ch == 'A' ||
            ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
        p++;
    }

    printf("Vowel Count = %d\n", count);
    return 0;
}

Problem 4: Dynamic Array Allocation and Input
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("You entered:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}

Problem 5: Access 2D Array Using Pointer to Pointer
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 2, cols = 3;
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    // Assign values
    int val = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = val++;

    // Print matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
