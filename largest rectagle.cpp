#include <stdio.h>

#define MAX 100000

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

int largestRectangle(int h[], int n) {
    int maxArea = 0;
    top = -1;

    int i = 0;

    while (i < n) {
        if (top == -1 || h[peek()] <= h[i]) {
            push(i++);
        } else {
            int tp = pop();
            int width;

            if (top == -1)
                width = i;
            else
                width = i - peek() - 1;

            int area = h[tp] * width;

            if (area > maxArea)
                maxArea = area;
        }
    }

    while (top != -1) {
        int tp = pop();
        int width;

        if (top == -1)
            width = i;
        else
            width = i - peek() - 1;

        int area = h[tp] * width;

        if (area > maxArea)
            maxArea = area;
    }

    return maxArea;
}

int main() {
    int n;
    scanf("%d", &n);

    int h[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    printf("%d\n", largestRectangle(h, n));

    return 0;
}

