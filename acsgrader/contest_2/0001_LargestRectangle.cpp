#include <climits>
#include <stdio.h>

int m_min(int a, int b, int *arr) {
    if (a == b) {
        return a;
    }
    int min = INT_MAX;
    for (int i=a; i<=b; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } 
    }

    return min;
}

int main() {
    int n;
    scanf("%d ", &n);
    
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]); 
    }
    
    int area, ans = INT_MIN;
    for (int j=0; j<n; j++) {
        for (int k=j; k<n; k++) {
            area = (k - j + 1) * m_min(j, k, arr);
            ans = (area > ans) ? area : ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}
