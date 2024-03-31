#include <bits/stdc++.h>
using namespace std;

int a[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
/*int get_element(int* arr, int x, int y, int i, int j) {
    int index = i * y + j;
    return *(arr + index);
} */

void flood(int *arr, int x, int y, int i, int j, int color) {
    if (i < 0 || j < 0 || i >= x || j >= y) {
        return;
    }

    if (*(arr + i*y + j) != color) {
        return;
    }
    *(arr + i*y + j) = 8;

    for (int k = 0; k < 4; k++) {
        flood(arr, x, y, i + a[k][0], j + a[k][1], color);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, M;
    cin >> x >> y >> M;
    int p, q;
    cin >> p >> q;

    int arr[x][y];
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            cin >> arr[i][j];
        }
    }

    int color = arr[p][q];
    flood(&arr[0][0], x, y, p, q, color);

    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
