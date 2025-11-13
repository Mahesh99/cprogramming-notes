What is a Structure in C?
A structure in C is a user-defined data type that allows combining variables of different types under a single name. It helps in grouping related data together.

Syntax of Structure
struct StructureName {
    dataType member1;
    dataType member2;
    ...
};
You can create a variable like this:
struct StructureName variableName;
__________________________________________________________________________________
#include <stdio.h>
struct Student {
    int id;
    char name[50];
    float marks;
};
int main() {
    struct Student s1 = {1, "Samual", 87.5};
    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);    
    return 0;
}
1) Program to Store and Display Student Information
#include <stdio.h>
struct Student {
    int id;
    char name[50];
 float percentage;
};
int main() {
    struct Student s1 = {101, "Anita", 92.5};
    printf("Student ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Percentage: %.2f\n", s1.percentage);
    return 0;
}

2.  Program to Take User Input into Structure
#include <stdio.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp;
    printf("Enter ID: ");
    scanf("%d", &emp.id);
     printf("Enter Name: ");
    scanf("%s", emp.name);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    printf("\nEmployee Details:\n");
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    return 0;
}

 Array of Structures to Store Multiple Students
#include <stdio.h>
struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[3];
    for(int i = 0; i < 3; i++) {
        printf("Enter roll, name and marks of student %d:\n", i + 1);
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }
    printf("\nStudent Information:\n");
    for(int i = 0; i < 3; i++) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
    return 0;
}

 Structure Inside Another Structure (Nested Structure)
#include <stdio.h>
struct Date {
    int day, month, year;
};
struct Employee {
    int id;
    char name[50];
    struct Date joiningDate;
};

int main() {
    struct Employee e = {1001, "Ravi", {15, 7, 2020}};
        printf("Employee ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Joining Date: %02d/%02d/%04d\n", e.joiningDate.day, e.joiningDate.month, e.joiningDate.year);
    return 0;
}

Pass Structure to Function
#include <stdio.h>
struct Book {
    char title[50];
    float price;
};

void display(struct Book b) {
    printf("Book Title: %s\n", b.title);
    printf("Price: %.2f\n", b.price);
}

int main() {
    struct Book b1 = {"C Programming", 399.50};
    display(b1);

    return 0;
}

Structure Pointers?
A pointer to a structure is used to access the structure using memory address.
You can use the -> operator to access members through a pointer.
struct StructName {
    dataType member;
};

int main() {
    struct StructName obj;
    struct StructName *ptr = &obj;
    ptr->member = value; // OR (*ptr).member = value;
}

#include <stdio.h>
struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person p1 = {"Kalyani", 25};
    struct Person *ptr = &p1;
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);
    return 0;
}
Dynamic Memory Allocation with Structures

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    float marks;
};

int main() {
    struct Student *s;
    s = (struct Student *)malloc(sizeof(struct Student));
    printf("Enter student ID: ");
    scanf("%d", &s->id);
    printf("Enter marks: ");
    scanf("%f", &s->marks);
    printf("\nStudent Details:\n");
    printf("ID: %d\n", s->id);
    printf("Marks: %.2f\n", s->marks);
    free(s);  // Free the allocated memory
    return 0;
}
__________________________________________________________________________________What is typedef?
The typedef keyword in C is used to create an alias (shortcut name) for another data type.
When used with struct, it helps to avoid writing struct again and again while declaring structure variables.

typedef struct {
    dataType member1;
    dataType member2;
} AliasName;
Now, instead of writing struct, you can use AliasName to declare variables.


typedef struct {
    int id;
    char name[50];
} Student;

Student s1;  // No need to write 'struct'

#include <stdio.h>

typedef struct {
    int id;
    char name[50];
} Employee;

int main() {
    Employee e1 = {101, "Ravi"};

    printf("ID: %d\n", e1.id);
    printf("Name: %s\n", e1.name);

    return 0;
}

typedef with Structure and Pointer
#include <stdio.h>

typedef struct {
    int roll;
    float marks;
} Student;

int main() {
    Student s1 = {10, 92.5};
    Student *ptr = &s1;

    printf("Roll: %d\n", ptr->roll);
    printf("Marks: %.2f\n", ptr->marks);

    return 0;
}

