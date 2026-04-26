#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

// Display
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

// Delete first
void delete_beg() {
    struct node *temp, *last;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    free(temp);
}

// Delete end
void delete_end() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// Main
int main() {
    int ch;

    while (1) {
        printf("\n1.Delete Begin\n2.Delete End\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: delete_beg(); break;
            case 2: delete_end(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
}
