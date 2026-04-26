#include <stdio.h>

int main() {
    int n, i;
    float marks[100], total = 0, average;

    // Input number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Input marks of students
    printf("Enter the marks of %d students:\n", n);
    for(i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &marks[i]);
        total += marks[i];
    }

    // Calculate average
    average = total / n;

    // Display results
    printf("\nTotal Marks = %.2f\n", total);
    printf("Average Marks = %.2f\n", average);

    return 0;
}
