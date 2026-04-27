#include <stdio.h>
#include <string.h>

int main() {
    int n, q;
    char strings[1000][100];
    char queries[1000][100];

    scanf("%d", &n);

    // input strings
    for(int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    scanf("%d", &q);

    // input queries
    for(int i = 0; i < q; i++) {
        scanf("%s", queries[i]);
    }

    // for each query count occurrences
    for(int i = 0; i < q; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}

