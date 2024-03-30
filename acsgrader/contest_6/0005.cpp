#include <iostream>
#include <vector>
using namespace std;

int longest_peak(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dwn(n, 0), upp(n, 0);
    int peak = 0;

    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] > arr[i + 1]) {
            dwn[i] = dwn[i + 1] + 1;
        }
    }

    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i - 1]) {
            upp[i] = upp[i - 1] + 1;
        }
        if(upp[i - 1] > 0 && dwn[i] > 0) {
            peak = max(peak, upp[i - 1] + dwn[i] + 1);
        }
    }

    return peak + 1;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int& val : arr) {
        cin >> val;
    }

    cout << longest_peak(arr) << endl;

    return 0;
}

