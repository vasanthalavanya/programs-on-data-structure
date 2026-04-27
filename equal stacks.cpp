#include <stdio.h>

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int h1[n1], h2[n2], h3[n3];

    // input stacks
    for(int i = 0; i < n1; i++) scanf("%d", &h1[i]);
    for(int i = 0; i < n2; i++) scanf("%d", &h2[i]);
    for(int i = 0; i < n3; i++) scanf("%d", &h3[i]);

    // compute total heights
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for(int i = 0; i < n1; i++) sum1 += h1[i];
    for(int i = 0; i < n2; i++) sum2 += h2[i];
    for(int i = 0; i < n3; i++) sum3 += h3[i];

    int i1 = 0, i2 = 0, i3 = 0;

    // remove from top until equal
    while(1) {
        if(i1 == n1 || i2 == n2 || i3 == n3)
            break;

        if(sum1 == sum2 && sum2 == sum3) {
            printf("%d", sum1);
            return 0;
        }

        // remove from tallest stack
        if(sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i1++];
        }
        else if(sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[i2++];
        }
        else {
            sum3 -= h3[i3++];
        }
    }

    printf("0");
    return 0;
}

