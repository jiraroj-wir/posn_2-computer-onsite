#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> ans;
    for (int j=0; j<n; j++) {
        int k = (j+1)%n;
        do {
            if (arr[j] < arr[k%n]) {
                ans.push_back(arr[k%n]);
                break;
            }
            if (k - j > n) {
                ans.push_back(-1);
                break;
            }
            k++;
        } while(true);
    }

    for (auto idx : ans) {
        cout << idx << ' ';
    }

    return 0;
}
