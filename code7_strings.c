Strings:

Strings are used for storing text/characters.
For example, "Hello World" is a string of characters.
Unlike many other programming languages, C does not have a String type to easily create string variables. Instead, you must use the char type and create an array of characters to make a string in C

Note that you have to use double quotes ("").
To output the string, you can use the printf() function together with the format specifier %s to tell C that we are now working with strings:


#include <stdio.h>

int main() {
  char greetings[] = "Hello World!";
  printf("%s", greetings);
 
  return 0;
}

Another Way Of Creating Strings
#include <stdio.h>

int main() {
  char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
  char greetings2[] = "Hello World!";
  
  printf("%s\n", greetings);
  printf("%s\n", greetings2);
  
  return 0;
}

Why do we include the \0 character at the end? This is known as the "null terminating character", and must be included when creating strings using this method. It tells C that this is the end of the string.

Differences
The difference between the two ways of creating strings, is that the first method is easier to write, and you do not have to include the \0 character, as C will do it for you.
You should note that the size of both arrays is the same: They both have 13 characters (space also counts as a character by the way), including the \0 character:
#include <stdio.h>
int main() {
  char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
  char greetings2[] = "Hello World!";
  
  printf("%zu\n", sizeof(greetings));
  printf("%zu\n", sizeof(greetings2));
  
  return 0;
}
___________________________
#include <stdio.h>

int main() {
  char message[] = "Good to see you,";
  char fname[] = "John";

  printf("%s %s!", message, fname);
 
  return 0;
}
Access Strings:
#include <stdio.h>
int main() {
  char greetings[] = "Hello World!";
  printf("%c", greetings[0]);
 
  return 0;
}

Modify Strings
#include <stdio.h>

int main() {
  char greetings[] = "Hello World!";
  greetings[0] = 'J';
  printf("%s", greetings);

  return 0;
}

Loop Through a String
#include <stdio.h>

int main() {
  char carName[] = "Volvo";
  int i;
  
  for (i = 0; i < 5; ++i) {
    printf("%c\n", carName[i]);
  }

  return 0;
}

And like we specified in the arrays chapter, you can also use the sizeof formula (instead of manually write the size of the array in the loop condition (i < 5)) to make the loop more sustainable:

#include <stdio.h>

int main() {
  char carName[] = "Volvo";
  int length = sizeof(carName) / sizeof(carName[0]);
  int i;
  
  for (i = 0; i < length; ++i) {
    printf("%c\n", carName[i]);
  }

  return 0;
}

C - Special Characters
Because strings must be written within quotes, C will misunderstand this string, and generate an error:

char txt[] = "We are the so-called "Vikings" from the north.";

The solution to avoid this problem, is to use the backslash escape character.
The backslash (\) escape character turns special characters into string characters:
Escape characterResultDescription\''Single quote\""Double quote\\\BackslashThe sequence \"  inserts a double quote in a string:

#include <stdio.h>
int main() {
  char txt[] = "We are the so-called \"Vikings\" from the north.";
  printf("%s", txt);
 
  return 0;
}
**************************
#include <stdio.h>
int main() {
  char txt[] = "It\'s alright.";
  printf("%s", txt);
 
  return 0;
}
******************************

#include <stdio.h>
int main() {
  char txt[] = "The character \\ is called backslash.";
  printf("%s", txt);
 
  return 0;
}


C - String Functions
C also has many useful string functions, which can be used to perform certain operations on strings.
To use them, you must include the <string.h> header file in your program:

String Length
#include <stdio.h>
#include <string.h>
 
int main() {
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  printf("%zu", strlen(alphabet));
  return 0;
}


Sizeof() / strlen()

In the Strings chapter, we used sizeof to get the size of a string/array. Note that sizeof and strlen behaves differently, as sizeof also includes the \0 character when counting:#include <stdio.h>

#include <string.h> 
int main() {
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  printf("Length is: %zu\n", strlen(alphabet));
  printf("Size is: %zu\n", sizeof(alphabet));
  return 0;
}

Output:
Length is: 26
Size is: 27


#include <stdio.h>
#include <string.h>
 
int main() {
  char alphabet[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  printf("Length is: %zu\n", strlen(alphabet));
  printf("Size is: %zu\n", sizeof(alphabet));
  return 0;
}

Concatenate Strings: To concatenate (combine) two strings, you can use the strcat() function:
#include <stdio.h>
#include <string.h>
 
int main() {
  char str1[20] = "Hello ";
  char str2[] = "World!";
 
  // Concatenate str2 to str1 (the result is stored in str1)
  strcat(str1, str2);
  
  // Print str1
  printf("%s", str1);
 
  return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
  char str1[20] = "Hello World!";
  char str2[20];

  // Copy str1 to str2
  strcpy(str2, str1);

  // Print str2
  printf("%s", str2);
  
  return 0;
}

Compare Strings:

#include <stdio.h>
#include <string.h>
int main() {
  char str1[] = "Hello";
  char str2[] = "Hello";
  char str3[] = "Hi";

  // Compare str1 and str2, and print the result
  printf("%d\n", strcmp(str1, str2));
  
  // Compare str1 and str3, and print the result
  printf("%d\n", strcmp(str1, str3));
  
  return 0;
}


C - User Input

You have already learned that printf() is used to output values in C.
To get user input, you can use the scanf() function:

The scanf() function takes two arguments: the format specifier of the variable (%d in the example above) and the reference operator (&myNum), which stores the memory address of the variable.

The scanf() function also allow multiple inputs (an integer and a character in the following example):

#include <stdio.h>
int main() {
  // Create an int and a char variable
  int myNum;
  char myChar;

  // Ask the user to type a number AND a character
  printf("Type a number AND a character and press enter: \n");

  // Get and save the number AND character the user types
  scanf("%d %c", &myNum, &myChar);

  // Print the number
  printf("Your number is: %d\n", myNum);

  // Print the character
  printf("Your character is: %c\n", myChar);
  
  return 0;
}


Take String Input
#include <stdio.h>
int main() {
  // Create a string
  char firstName[30];

  // Ask the user to input some text (name)
  printf("Enter your first name and press enter: \n");

  // Get and save the text
  scanf("%s", firstName);

  // Output the text
  printf("Hello %s", firstName);
  
  return 0;
}

Note: When working with strings in scanf(), you must specify the size of the string/array (we used a very high number, 30 in our example, but at least then we are certain it will store enough characters for the first name), and you don't have to use the reference operator (&).

However, the scanf() function has some limitations: it considers space (whitespace, tabs, etc) as a terminating character, which means that it can only display a single word (even if you type many words). For example:
char fullName[30];

printf("Type your full name: \n");
scanf("%s", &fullName);

printf("Hello %s", fullName);

// Type your full name: John Doe
// Hello John

From the example above, you would expect the program to print "John Doe", but it only prints "John".
That's why, when working with strings, we often use the fgets() function to read a line of text. Note that you must include the following arguments: the name of the string variable, sizeof(string_name), and stdin:
#include <stdio.h>

int main() {  // Create a string
  char fullName[30];

  // Ask the user to input some text (full name)
  printf("Type your full name and press enter: \n");

  // Get the text
  fgets(fullName, sizeof(fullName), stdin);
  // Output the text
  printf("Hello %s", fullName);
  return 0;
}

#include <stdio.h>
int main() {
  // Create a string
  char fullName[30];
  // Ask the user to input some text (full name)
  printf("Type your full name and press enter: \n");
  // Get the text
  fgets(fullName, sizeof(fullName), stdin);
  // Output the text
  printf("Hello %s", fullName);
    return 0;
}


