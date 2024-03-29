#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=i+1; j<=n; j++) {
            cnt++;
            if (i == n-1 || j == n) {
                cout << '0' << ' ';
                break;
            }
            if (arr[j] > arr[i]) {
                cout << cnt << ' ';
                break;
            } 
        }
    }

    return 0;
}
