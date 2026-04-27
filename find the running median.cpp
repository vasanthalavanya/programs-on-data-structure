#include <stdio.h>

#define MAX 100000

int maxHeap[MAX];
int minHeap[MAX];

int maxSize = 0, minSize = 0;

// ---------- MAX HEAP ----------
void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        int t = maxHeap[i];
        maxHeap[i] = maxHeap[(i - 1) / 2];
        maxHeap[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

void maxInsert(int val) {
    maxHeap[maxSize] = val;
    maxHeapifyUp(maxSize);
    maxSize++;
}

int maxExtract() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];

    int i = 0;
    while (2 * i + 1 < maxSize) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < maxSize && maxHeap[l] > maxHeap[largest])
            largest = l;
        if (r < maxSize && maxHeap[r] > maxHeap[largest])
            largest = r;

        if (largest == i) break;

        int t = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = t;
        i = largest;
    }

    return root;
}

// ---------- MIN HEAP ----------
void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        int t = minHeap[i];
        minHeap[i] = minHeap[(i - 1) / 2];
        minHeap[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

void minInsert(int val) {
    minHeap[minSize] = val;
    minHeapifyUp(minSize);
    minSize++;
}

int minExtract() {
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];

    int i = 0;
    while (2 * i + 1 < minSize) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < minSize && minHeap[l] < minHeap[smallest])
            smallest = l;
        if (r < minSize && minHeap[r] < minHeap[smallest])
            smallest = r;

        if (smallest == i) break;

        int t = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = t;
        i = smallest;
    }

    return root;
}

// ---------- BALANCE ----------
void balance() {
    if (maxSize > minSize + 1) {
        minInsert(maxExtract());
    } 
    else if (minSize > maxSize) {
        maxInsert(minExtract());
    }
}

// ---------- MAIN ----------
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (maxSize == 0 || x <= maxHeap[0])
            maxInsert(x);
        else
            minInsert(x);

        balance();

        if (maxSize == minSize) {
            double median = (maxHeap[0] + minHeap[0]) / 2.0;
            printf("%.1f\n", median);
        } else {
            printf("%.1f\n", (double)maxHeap[0]);
        }
    }

    return 0;
}

