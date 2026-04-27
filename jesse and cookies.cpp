#include <stdio.h>
#include <stdlib.h>

void swap(long *a, long *b) {
    long t = *a;
    *a = *b;
    *b = t;
}

// Heapify down (min heap)
void heapify(long heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && heap[left] < heap[smallest])
        smallest = left;

    if(right < n && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Build heap
void buildHeap(long heap[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

// Extract min
long extractMin(long heap[], int *n) {
    long min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return min;
}

// Insert
void insertHeap(long heap[], int *n, long val) {
    int i = (*n)++;
    heap[i] = val;

    while(i > 0) {
        int parent = (i - 1) / 2;

        if(heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

int main() {
    int n;
    long k;
    scanf("%d %ld", &n, &k);

    long heap[n];

    for(int i = 0; i < n; i++) {
        scanf("%ld", &heap[i]);
    }

    int size = n;
    buildHeap(heap, size);

    int ops = 0;

    while(size > 1 && heap[0] < k) {
        long first = extractMin(heap, &size);
        long second = extractMin(heap, &size);

        long newVal = first + 2 * second;
        insertHeap(heap, &size, newVal);

        ops++;
    }

    if(heap[0] >= k)
        printf("%d", ops);
    else
        printf("-1");

    return 0;
}

