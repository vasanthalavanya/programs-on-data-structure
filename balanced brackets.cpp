#include <stdio.h>
#include <string.h>

#define MAX 100000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *s) {
    top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // opening brackets
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
        // closing brackets
        else {
            if (isEmpty())
                return 0;

            char topChar = pop();

            if (!isMatching(topChar, c))
                return 0;
        }
    }

    return isEmpty();
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char s[100000];
        scanf("%s", s);

        if (isBalanced(s))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

