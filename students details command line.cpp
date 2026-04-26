#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int m1, m2, m3, total;
    char name[50];

    // Check correct number of arguments
    if (argc != 5) {
        printf("Usage: <program> <name> <m1> <m2> <m3>\n");
        return 1;
    }

    // Read name
    sprintf(name, "%s", argv[1]);

    // Convert marks from string to integer
    m1 = atoi(argv[2]);
    m2 = atoi(argv[3]);
    m3 = atoi(argv[4]);

    // Calculate total
    total = m1 + m2 + m3;

    // Display output
    printf("Student Details:\n");
    printf("Name  : %s\n", name);
    printf("Marks : %d %d %d\n", m1, m2, m3);
    printf("Total : %d\n", total);

    return 0;
}
