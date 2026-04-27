#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000000

int minSteps(int n) {
    int *dist = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) dist[i] = INT_MAX;

    int *queue = (int *)malloc((n + 1) * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = n;
    dist[n] = 0;

    while (front < rear) {
        int u = queue[front++];

        if (u == 0) break;

        // Move 1: u -> u - 1
        if (u - 1 >= 0 && dist[u - 1] > dist[u] + 1) {
            dist[u - 1] = dist[u] + 1;
            queue[rear++] = u - 1;
        }

        // Move 2: factor moves
        for (int i = 2; i * i <= u; i++) {
            if (u % i == 0) {
                int a = i;
                int b = u / i;
                int next = (a > b) ? a : b;

                if (dist[next] > dist[u] + 1) {
                    dist[next] = dist[u] + 1;
                    queue[rear++] = next;
                }
            }
        }
    }

    int ans = dist[0];
    free(dist);
    free(queue);

    return ans;
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", minSteps(n));
    }

    return 0;
}

