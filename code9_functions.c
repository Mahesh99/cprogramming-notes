 C – Functions
A function is a block of code which only runs when it is called.
You can pass data, known as parameters, into a function.
Functions are used to perform certain actions, and they are important for reusing code: Define the code once, and use it many times.
 Create a Function
To create (often referred to as declare) your own function, specify the name of the function, followed by parentheses () and curly brackets {}:
 Syntax
void myFunction() {
// code to be executed
}
A function consist of two parts:
* Declaration: the function's name, return type, and parameters (if any)
* Definition: the body of the function (code to be executed)
void myFunction() { // declaration
  // the body of the function (definition)
}

myFunction() is the name of the function
* void means that the function does not have a return value. You will learn more about return values later in the next chapter
* Inside the function (the body), add code that defines what the function should do
 Call a Function
Declared functions are not executed immediately. They are "saved for later use", and will be executed when they are called.
To call a function, write the function's name followed by two parentheses () and a semicolon ;
In the following example, myFunction() is used to print a text (the action), when it is called:
#include <stdio.h>
// Create a function
void myFunction() {
  printf("I just got executed!");
}

int main() {
  myFunction(); // call the function
  return 0;
}

A function can be called multiple times:
#include <stdio.h>
// Create a function
void myFunction() {
  printf("I just got executed!\n");
}

int main() {
  myFunction(); // call the function
  myFunction(); // call the function
  myFunction(); // call the function
  return 0;
}
 Calculate the Sum of Numbers
#include <stdio.h>
// Create a function
void calculateSum() {
  int x = 5;
  int y = 10;
  int sum = x + y;
  printf("The sum of x + y is: %d", sum);
}
int main() {
  calculateSum();  // call the function
  return 0;
}
 Parameters and Arguments
Information can be passed to functions as a parameter. Parameters act as variables inside the function.
Parameters are specified after the function name, inside the parentheses. You can add as many parameters as you want, just separate them with a comma:
takes a string of characters with name as parameter. When the function is called, we pass along a name, which is used inside the function to print "Hello" and the name of each person:

#include <stdio.h>
void myFunction(char name[]) {
  printf("Hello %s\n", name);
}
int main() {
  myFunction("Liam");
  myFunction("Jenny");
  myFunction("Anja");
  return 0;
}

 Multiple Parameters
#include <stdio.h>
void calculateSum(int x, int y) {
  int sum = x + y;
  printf("The sum of %d + %d is: %d\n", x, y, sum);
}
int main() {
  calculateSum(5, 3);
  calculateSum(8, 2);
  calculateSum(15, 15);
  return 0;
}

 Pass Arrays as Function Parameters
#include <stdio.h>
void myFunction(int myNumbers[5]) {
  for (int i = 0; i < 5; i++) {
    printf("%d\n", myNumbers[i]);
  }
}
int main() {
  int myNumbers[5] = {10, 20, 30, 40, 50};  
  myFunction(myNumbers);
  return 0;
}

 Return Values
The void keyword, indicates that the function should not return a value. If you want the function to return a value, you can use a data type (such as int or float, etc.) instead of void, and use the return keyword inside the function:

#include <stdio.h>
int myFunction(int x) {
  return 5 + x;
}
int main() {
  printf("Result is: %d", myFunction(3));
  return 0;
}

#include <stdio.h>
int calculateSum(int x, int y) {
  return x + y;
}
int main() {
  int result1 = calculateSum(5, 3);
  int result2 = calculateSum(8, 2);
  int result3 = calculateSum(15, 15);
  printf("Result1 is: %d\n", result1);
  printf("Result2 is: %d\n", result2);
  printf("Result3 is: %d\n", result3);
  return 0;
}

Tip: If you have many "result variables", it is better to store the results in an array:
#include <stdio.h>
int calculateSum(int x, int y) {
  return x + y;
}
int main() {
  // Create an array
  int resultArr[6];
  // Call the function with different arguments and store the different results in the array
  resultArr[0] = calculateSum(5, 3);
  resultArr[1] = calculateSum(8, 2);
  resultArr[2] = calculateSum(15, 15);
  resultArr[3] = calculateSum(9, 1);
  resultArr[4] = calculateSum(7, 7);
  resultArr[5] = calculateSum(1, 1);

  for (int i = 0; i < 6; i++) {
    printf("Result%d is = %d\n", i + 1, resultArr[i]);
  }

  return 0;
}

 create a program that converts a value from fahrenheit to celsius:

#include <stdio.h>
// Function to convert Fahrenheit to Celsius
float toCelsius(float fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit - 32.0);
}
int main() {
  // Set a fahrenheit value
  float f_value = 98.8;
    // Call the function with the fahrenheit value
  float result = toCelsius(f_value);
  // Print the fahrenheit value
  printf("Fahrenheit: %.2f\n", f_value);
    // Print the result
  printf("Convert Fahrenheit to Celsius: %.2f\n", result);
  return 0;
}

 C Variable Scope
 It is important to learn how variables act inside and outside of functions
A variable created inside a function belongs to the local scope of that function, and can only be used inside that function:

#include <stdio.h>
void myFunction() {
  // Local variable that belongs to myFunction
  int x = 5;

  // Print the variable x
  printf("%d", x);
}
int main() {
  myFunction();
  return 0;
}

A local variable cannot be used outside the function it belongs to.
If you try to access it outside the function, an error occurs:
#include <stdio.h>
void myFunction() {
  // Local variable that belongs to myFunction
  int x = 5;
}
int main() {
  myFunction();

  // Print the variable x in the main function
  printf("%d", x);
  return 0;
}

 Global Scope
A variable created outside of a function, is called a global variable and belongs to the global scope.
Global variables are available from within any scope, global and local:
#include <stdio.h>
// Global variable x
int x = 5;
void myFunction() {
  // We can use x here
  printf("%d\n", x);
}
int main() {
  myFunction();

  // We can also use x here
  printf("%d\n", x);
  return 0;
}

 C Recursion
Recursion is the technique of making a function call itself. This technique provides a way to break complicated problems down into simple problems which are easier to solve.

 Recursion Example
Adding two numbers together is easy to do, but adding a range of numbers is more complicated. In the following example, recursion is used to add a range of numbers together by breaking it down into the simple task of adding two numbers:
#include <stdio.h>
int sum(int k);
int main() {
  int result = sum(10);
  printf("%d", result);
  return 0;
}
int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}

When the sum() function is called, it adds parameter k to the sum of all numbers smaller than k and returns the result. When k becomes 0, the function just returns 0. When running, the program follows these steps:
10 + sum(9)
10 + ( 9 + sum(8) )
10 + ( 9 + ( 8 + sum(7) ) )
...
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + sum(0)
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + 0
Since the function does not call itself when k is 0, the program stops there and returns the result.
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + sum(0)
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + 0
...
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + sum(0)
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + 0
