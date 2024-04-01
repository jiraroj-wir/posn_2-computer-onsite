#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int idx_d, val_d;
    cin >> idx_d >> val_d;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i != j && abs(i - j) <= idx_d && abs(arr[i] - arr[j]) <= val_d) {
                cout << "Y" << endl;
                return 0;
            }
        }
    }

    cout << 'N' << endl;
    return 0;
}
