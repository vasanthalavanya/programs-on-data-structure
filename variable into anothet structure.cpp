#include <stdio.h>

// Define a structure
struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    // Declare two structure variables
    struct Student s1, s2;

    // Assign values to first structure
    s1.id = 101;
    sprintf(s1.name, "John");
    s1.marks = 89.5;

    // Copy s1 into s2
    s2 = s1;

    // Display values of s2 to verify copy
    printf("Copied Structure Details:\n");
    printf("ID: %d\n", s2.id);
    printf("Name: %s\n", s2.name);
    printf("Marks: %.2f\n", s2.marks);

    return 0;
}
