#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

// Display
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete first node
void delete_first() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

// Delete last node
void delete_last() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Delete at position
void delete_posi() {
    struct node *temp, *t;
    int posi, i = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &posi);

    temp = head;

    if (posi == 1) {
        head = head->next;
        free(temp);
        return;
    }

    while (i < posi - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    t = temp->next;
    temp->next = t->next;
    free(t);
}

// Main
int main() {
    int ch;

    while (1) {
        printf("\n1.Delete First\n2.Delete Last\n3.Delete Position\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: delete_first(); break;
            case 2: delete_last(); break;
            case 3: delete_posi(); break;
            case 4: display(); break;
            case 5: exit(0);
        }
    }
    return 0;
}
