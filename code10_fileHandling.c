File Handling

In C, file handling is done using the standard I/O library (stdio.h). It allows programs to read from and write to files. The main operations are:

?? Steps to Work with Files in C
1. Declare a File Pointer
2. Open the File using fopen()
3. Perform Read/Write operations
4. Close the File using fclose()

?? File Pointer

FILE *fp;

?? Opening a File

fp = fopen("filename.txt", "mode");
Common Modes:
ModeDescription"r"Open for reading"w"Open for writing (erases file)"a"Open for appending"r+"Read & write (start of file)"w+"Write & read (erases file)"a+"Read & append
?? Example: Write to File

#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("example.txt", "w");

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    fprintf(fp, "Hello, File in C!\n");
    fclose(fp);

    return 0;
}

?? Example: Read from File

#include <stdio.h>

int main() {
  FILE *fptr;

  // Open a file in read mode
  fptr = fopen("filename.txt", "r");

  // Store the content of the file
  char myString[100];

  // Read the content and store it inside myString
  fgets(myString, 100, fptr);

  // Print file content
  printf("%s", myString);  
  
  // Close the file
  fclose(fptr);

  return 0;
}

Note: The fgets function only reads the first line of the file. If you remember, there were two lines of text in filename.txt.
To read every line of the file, you can use a while loop:
#include <stdio.h>
int main() {
  FILE *fptr;
  // Open a file in read mode
  fptr = fopen("filename.txt", "r");
  // Store the content of the file
  char myString[100];
  // Read the content and print it
  while(fgets(myString, 100, fptr)) {
    printf("%s", myString);
  }
  // Close the file
  fclose(fptr);
  return 0;
}

 Common File Functions
FunctionPurposefopen()Open a filefclose()Close the filefprintf()Write formatted outputfscanf()Read formatted inputfputc()Write a characterfgetc()Read a characterfputs()Write a stringfgets()Read a string
In C, we use return 1; (or any non-zero value) in the main() function to indicate that the program did not run successfully — usually because of an error.
int main() {
    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;  // Error occurred
    }

    // ... normal code
    return 0;  // Program ended successfully
}

Append Content To a File

If you want to add content to a file without deleting the old content, you can use the a mode.
The a mode appends content at the end of the file:
#include <stdio.h>

int main() {
  FILE *fptr;

  // Open a file in append mode
  fptr = fopen("filename.txt", "a");

  // Append some text to the file
  fprintf(fptr, "\nHi everybody!");
  
  // Close the file
  fclose(fptr);

  return 0;
}

