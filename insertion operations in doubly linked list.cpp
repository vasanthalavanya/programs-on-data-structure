#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL;

// Display
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
void insert_beg() {
    struct node *new_node;
    int ele;

    new_node = (struct node*)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &ele);

    new_node->data = ele;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
        head->prev = new_node;

    head = new_node;
}

// Insert at end
void insert_end() {
    struct node *new_node, *temp;
    int ele;

    new_node = (struct node*)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &ele);

    new_node->data = ele;
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
}

// Insert at position
void insert_posi() {
    struct node *new_node, *temp;
    int ele, pos, i = 1;

    new_node = (struct node*)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &ele);
    printf("Enter position: ");
    scanf("%d", &pos);

    new_node->data = ele;

    if (pos == 1) {
        new_node->prev = NULL;
        new_node->next = head;

        if (head != NULL)
            head->prev = new_node;

        head = new_node;
        return;
    }

    temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new_node;

    temp->next = new_node;
}

// Main
int main() {
    int ch;

    while (1) {
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Position\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_beg(); break;
            case 2: insert_end(); break;
            case 3: insert_posi(); break;
            case 4: display(); break;
            case 5: exit(0);
        }
    }
}
