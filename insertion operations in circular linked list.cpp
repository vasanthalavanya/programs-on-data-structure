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

// Insert at beginning
void insert_beg() {
    struct node *new_node, *temp;
    int ele;

    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &ele);

    new_node->data = ele;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        new_node->next = head;
        temp->next = new_node;
        head = new_node;
    }
}

// Insert at end
void insert_end() {
    struct node *new_node, *temp;
    int ele;

    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &ele);

    new_node->data = ele;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = new_node;
        new_node->next = head;
    }
}

// Main
int main() {
    int ch;

    while (1) {
        printf("\n1.Insert Begin\n2.Insert End\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_beg(); break;
            case 2: insert_end(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
}
