#include <stdio.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int arr[n], res[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    d = d % n;  // handle large rotations

    for (int i = 0; i < n; i++) {
        res[i] = arr[(i + d) % n];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}

