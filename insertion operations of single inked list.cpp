#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

// Display function
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

// Insert at beginning
void insert_beg() {
    struct node *new_node;
    int ele;

    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &ele);

    new_node->data = ele;
    new_node->next = head;
    head = new_node;
}

// Insert at last
void insert_last() {
    struct node *new_node, *temp;
    int ele;

    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &ele);

    new_node->data = ele;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Insert at position
void insert_posi() {
    struct node *new_node, *temp;
    int ele, posi, i = 1;

    new_node = (struct node*)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &ele);
    printf("Enter position: ");
    scanf("%d", &posi);

    new_node->data = ele;

    if (posi == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    temp = head;
    while (i < posi - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Main function
int main() {
    int ch;

    while (1) {
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Position\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_beg(); break;
            case 2: insert_last(); break;
            case 3: insert_posi(); break;
            case 4: display(); break;
            case 5: exit(0);
        }
    }
    return 0;
}
