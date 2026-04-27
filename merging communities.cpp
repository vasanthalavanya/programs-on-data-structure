#include <stdio.h>

#define MAX 100000

int parent[MAX];
int size[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_set(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        if (size[rootA] < size[rootB]) {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        } else {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    while (q--) {
        char type;
        int x, y;

        scanf(" %c", &type);

        if (type == 'M') {
            scanf("%d %d", &x, &y);
            union_set(x, y);
        } else if (type == 'Q') {
            scanf("%d", &x);
            int root = find(x);
            printf("%d\n", size[root]);
        }
    }

    return 0;
}

