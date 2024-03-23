#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    vector<int> arr;
    int num;
    for (int i=0; i<n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());

    vector<int> d;
    for (int i = 0; i < n - 1; i++) {
        int difference = arr[i+1] - arr[i];
        d.push_back(difference);
    }

    if (!d.empty()) {
        cout << *max_element(d.begin(), d.end()) << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
