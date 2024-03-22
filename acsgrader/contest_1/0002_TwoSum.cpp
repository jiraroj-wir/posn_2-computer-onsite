#include <stdio.h>
#define us unsigned short int

int main() {
    us n, size, arr[300];

    scanf("%hu %hu", &n, &size);
    for (us i=0; i<size; i++) {
        scanf("%hu", &arr[i]);
    }

    for (us j=0; j<size; j++) {
        for (us k=j+1; k<size; k++) {
            us sum_n = arr[j] + arr[k];
            if (n == sum_n) {
                printf("%hu %hu\n", j+1, k+1);
                return 0;
            }
        }
    }
    printf("-1 -1");

    return 0;
}