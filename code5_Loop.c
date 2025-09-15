While Loop

The while loop loops through a block of code as long as a specified condition is true
Syntax
while (condition) {
  // code block to be executed
}

#include <stdio.h>
int main() {
  int i = 0;  
  while (i < 5) {
    printf("%d\n", i);
    i++;
  }
    return 0;
}

Countdown
#include <stdio.h>
int main() {
  int countdown = 3;

  while (countdown > 0) {
    printf("%d\n", countdown);
    countdown--;
  }
  printf("Happy New Year!!\n");
  
  return 0;
}
Countdown
#include <stdio.h>

int main() {
  int countdown = 3;

  while (countdown > 0) {
    printf("%d\n", countdown);
    countdown--;
  }

  printf("Happy New Year!!\n");

  return 0;
}

The Do/While Loop
The do/while loop always runs at least once, even if the condition is already false. This is different from a regular while loop, which would skip the loop entirely if the condition is false at the start.
This behavior makes do/while useful when you want to ensure something happens at least once, like showing a message or asking for user input.
#include <stdio.h>

int main() {
  int number;

  do {
    printf("Enter a positive number: ");
    scanf("%d", &number);
  } while (number > 0);

  return 0;
}

To demonstrate a practical example of the while loop combined with an if else statement, let's say we play a game of Yatzy:

#include <stdio.h>
int main() {
  int dice = 1;
  
  while (dice <= 6) {
    if (dice < 6) {
      printf("No Yatzy\n");
    } else {
      printf("Yatzy!\n");
    }
    dice = dice + 1;
  }

  return 0;
}

For Loop

When you know exactly how many times you want to loop through a block of code, use the for loop instead of a while loop:

#include <stdio.h>

int main() {
  int i;

  for (i = 0; i < 5; i++) {
    printf("%d\n", i);
  }
  
  return 0;
}

This example prints even values between 0 and 10:
#include <stdio.h>

int main() {
  int i;
  
  for (i = 0; i <= 10; i = i + 2) {
    printf("%d\n", i);
  }
  
  return 0;
}

Sum of Numbers

#include <stdio.h>

int main() {
  int sum = 0;
  int i;

  for (i = 1; i <= 5; i++) {
    sum = sum + i;
  }

  printf("Sum is %d", sum);
  
  return 0;
}

This example prints a countdown from 5 to 1:

#include <stdio.h>

int main() {
  int i;

  for (i = 5; i > 0; i--) {
    printf("%d\n", i);
  }
  
  return 0;
}
Nested Loops
It is also possible to place a loop inside another loop. This is called a nested loop.
The "inner loop" will be executed one time for each iteration of the "outer loop":
#include <stdio.h>

int main() {
  int i, j;
  
  // Outer loop
  for (i = 1; i <= 2; ++i) {
    printf("Outer: %d\n", i);  // Executes 2 times
    
    // Inner loop
    for (j = 1; j <= 3; ++j) {
      printf(" Inner: %d\n", j);  // Executes 6 times (2 * 3)
    }
  }
  
  return 0;
}

nested loops to print a simple multiplication table (1 to 3): nested loops to print a simple multiplication table (1 to 3):

#include <stdio.h>

int main() {
  int i, j;

  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) {
      printf("%d ", i * j);
    }
    printf("\n");
  }
  
  return 0;
}

 for loop, let's create a program that counts to 100 by tens:
Example
#include <stdio.h>

int main() {
  int i;
  
  for (i = 0; i <= 100; i += 10) {
    printf("%d\n", i);
  }
  
  return 0;
}

create a program that only print even numbers between 0 and 10 (inclusive):

#include <stdio.h>

int main() {
  int i;
  
  for (i = 0; i <= 10; i = i + 2) {
    printf("%d\n", i);
  }
  
  return 0;
}

Here we only print odd numbers:

#include <stdio.h>

int main() {
  int i;
  
  for (i = 1; i < 10; i = i + 2) {
    printf("%d\n", i);
  }
  
  return 0;
}


print the powers of 2 up to 512:

#include <stdio.h>

int main() {
  int i;
  
  for (i = 2; i <= 512; i *= 2) {
    printf("%d\n", i);
  }    
  
  return 0;
}
 create a program that prints the multiplication table for a specified number:

#include <stdio.h>

int main() {
  int number = 2;
  int i;

  // Print the multiplication table for the number 2
  for (i = 1; i <= 10; i++) {
    printf("%d x %d = %d\n", number, i, number * i);
  }

  return 0;
}

Break and Continue

he break statement can also be used to jump out of a loop.
This example jumps out of the for loop when i is equal to 4:
#include <stdio.h>

int main() {
  int i;
  
  for (i = 0; i < 10; i++) {
    if (i == 4) {
      break;
    }
    printf("%d\n", i);
  }
   
  return 0;
}
Continue

The continue statement breaks one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.
This example skips the value of 4:

#include <stdio.h>

int main() {
  int i;
  
  for (i = 0; i < 10; i++) {
    if (i == 4) {
      continue;
    }
    printf("%d\n", i);
  }   
  
  return 0;
}

Break and Continue in While Loop
You can also use break and continue in while loops:

#include <stdio.h>

int main() {
  int i = 0;
  
  while (i < 10) {
    if (i == 4) {
      break;
    }
    printf("%d\n", i);
    i++;
  } 
  
  return 0;
}

#include <stdio.h>

int main() {
  int i = 0;
  
  while (i < 10) {
    if (i == 4) {
      i++;
      continue;
    }
    printf("%d\n", i);
    i++;
  } 
  
  return 0;
}

