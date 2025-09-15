Arrays
Arrays are used to store multiple values in a single variable, instead of declaring separate variables for each value.
To create an array, define the data type (like int) and specify the name of the array followed by square brackets [].
To insert values to it, use a comma-separated list inside curly braces, and make sure all values are of the same data type:
Eg: int myNumbers[] = {25, 50, 75, 100};

#include <stdio.h>
int main() {
  int myNumbers[] = {25, 50, 75, 100};
  printf("%d", myNumbers[0]);
 
  return 0;
}


Change an Array Element
#include <stdio.h>
int main() {
  int myNumbers[] = {25, 50, 75, 100};
  myNumbers[0] = 33;

  printf("%d", myNumbers[0]);
 
  return 0;
}

Loop Through an Array
#include <stdio.h>
int main() {
  int myNumbers[] = {25, 50, 75, 100};
  int i;
  
  for (i = 0; i < 4; i++) {
    printf("%d\n", myNumbers[i]);
  }
 
  return 0;
}

Get Array Size or Length
#include <stdio.h>
int main() {
  int myNumbers[] = {10, 25, 50, 75, 100};
  printf("%zu", sizeof(myNumbers));
 
  return 0;
}


Why did the result show 20 instead of 5, when the array contains 5 elements?
- It is because the sizeof operator returns the size of a type in bytes.
You learned from the Data Types chapter that an int type is usually 4 bytes, so from the example above, 4 x 5 (4 bytes x 5 elements) = 20 bytes.
Knowing the memory size of an array is great when you are working with larger programs that require good memory management.
But when you just want to find out how many elements an array has, you can use the following formula (which divides the size of the array by the size of the first element in the array):

#include <stdio.h>
int main() {
  int myNumbers[] = {10, 25, 50, 75, 100};
  int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
  
  printf("%d", length);
  return 0;
}

#include <stdio.h>
int main() {
  int myNumbers[] = {25, 50, 75, 100};
  int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
  int i;

  for (i = 0; i < length; i++) {
    printf("%d\n", myNumbers[i]);
  }
  
  return 0;
}


To demonstrate a practical example of using arrays, let's create a program that calculates the average of different ages:

#include <stdio.h>

int main() {
  // An array storing different ages
  int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};
 
  float avg, sum = 0;
  int i;
  
  // Get the length of the array
  int length = sizeof(ages) / sizeof(ages[0]);
    
  // Loop through the elements of the array and accumulate the sum
  for (i = 0; i < length; i++) {
    sum += ages[i];
  }
  
  // Calculate the average by dividing the sum by the length
  avg = sum / length;
  
  // Print the average
  printf("The average age is: %.2f", avg);
  
  return 0;
}

we create a program that finds the lowest age among different ages:

#include <stdio.h>

int main() {
   // An array storing different ages
  int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};
  
  int i;
  
  // Get the length of the array
  int length = sizeof(ages) / sizeof(ages[0]);
  
  // Create a 'lowest age' variable and assign the first array element of ages to it
  int lowestAge = ages[0];

  // Loop through the elements of the ages array to find the lowest age
  for (i = 0; i < length; i++) {
  
    // Check if the current age is smaller than current the 'lowest age'
    if (lowestAge > ages[i]) {
    
      // If the smaller age is found, update 'lowest age' with that element
      lowestAge = ages[i];
    }
  }
 
  // Output the value of the lowest age
  printf("The lowest age in the array is: %d", lowestAge);
   
  return 0;
}


C Multidimensional Arrays
Multidimensional Arrays
In the previous chapter, you learned about arrays, which is also known as single dimension arrays. These are great, and something you will use a lot while programming in C. However, if you want to store data as a tabular form, like a table with rows and columns, you need to get familiar with multidimensional arrays.
A multidimensional array is basically an array of arrays.
Arrays can have any number of dimensions. In this chapter, we will introduce the most common; two-dimensional arrays (2D).
Two-Dimensional Arrays
A 2D array is also known as a matrix (a table of rows and columns).
To create a 2D array of integers, take a look at the following example:
int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };


The first dimension represents the number of rows [2], while the second dimension represents the number of columns [3]. The values are placed in row-order, and can be visualized like this:


Access the Elements of a 2D Array
To access an element of a two-dimensional array, you must specify the index number of both the row and column.
This statement accesses the value of the element in the first row (0) and third column (2) of the matrix array.
#include <stdio.h>
int main() {
  int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
  printf("%d", matrix[0][2]);
 
  return 0;
}

Change Elements in a 2D Array
To change the value of an element, refer to the index number of the element in each of the dimensions:
The following example will change the value of the element in the first row (0) and first column (0):
#include <stdio.h>
int main() {
  int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
  matrix[0][0] = 9;
  printf("%d", matrix[0][0]);  // Now outputs 9 instead of 1
 
  return 0;
}

Loop Through a 2D Array
To loop through a multi-dimensional array, you need one loop for each of the array's dimensions.
The following example outputs all elements in the matrix array:
#include <stdio.h>
int main() {
  int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

  int i, j;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d\n", matrix[i][j]);
    }
  }
    return 0;
}

Three-Dimensional Arrays
You can also declare arrays with more than two dimensions:
#include <stdio.h>
int main() {
  // A 3D array with 2 blocks, each with 4 rows and 3 columns
  int example[2][4][3] = {
    {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}
    },
    {
      {13, 14, 15}, {16, 17, 18}, {19, 20, 21}, {22, 23, 24}
    }
  };

  // Print all elements using 3 nested loops
  for (int i = 0; i < 2; i++) {
    printf("Block %d:\n", i + 1);
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 3; k++) {
        printf("%d ", example[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}

#include <stdio.h>

int main() {
  // A 3D array with 2 blocks, each with 4 rows and 3 columns
  int example[2][4][3] = {
    {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}
    },
    {
      {13, 14, 15}, {16, 17, 18}, {19, 20, 21}, {22, 23, 24}
    }
  };

  // Print all elements using 3 nested loops
  for (int i = 0; i < 2; i++) {
    printf("Block %d:\n", i + 1);
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 3; k++) {
        printf("%d ", example[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}

This creates a 3D array with:
* 2 blocks (first index)
* 4 rows per block (second index)
* 3 columns per row (third index)

When to Use Multidimensional Arrays
Multidimensional arrays are useful when your data is arranged in rows and columns, like a table, grid, or matrix.
Each extra dimension adds another level of structure:
* 2D arrays (like int scores[3][4]) are great for storing things like scores, game boards, or spreadsheets
* 3D arrays (like int cube[2][3][4]) can represent more complex structures like a set of tables or levels in a game

