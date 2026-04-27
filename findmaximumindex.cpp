#include <stdio.h>

#define MAX 1000005

int stack[MAX];

void computeLeft(int n, int a[], int L[]) {
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && a[stack[top]] <= a[i]) {
            top--;
        }

        L[i] = (top == -1) ? 0 : stack[top] + 1; // 1-based index
        stack[++top] = i;
    }
}

void computeRight(int n, int a[], int R[]) {
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && a[stack[top]] <= a[i]) {
            top--;
        }

        R[i] = (top == -1) ? 0 : stack[top] + 1; // 1-based index
        stack[++top] = i;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n], L[n], R[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    computeLeft(n, a, L);
    computeRight(n, a, R);

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long prod = (long long)L[i] * R[i];
        if (prod > ans) ans = prod;
    }

    printf("%lld\n", ans);

    return 0;
}

