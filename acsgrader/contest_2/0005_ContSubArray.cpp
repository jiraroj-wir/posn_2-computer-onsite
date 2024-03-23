#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<int> arr;

void sub_arr(int i, int _min, int _max) {
    int num = arr[i];
    _min = min(_min, num);
    _max = max(_max, num);
    if (_max - _min <=2 && n>i) {
        cout << _max << ' ' << _min << endl;
        cnt++;
        if (abs(num - arr[i+1]) <= 2) {
            sub_arr(i+1, _min, _max);
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin.ignore();

    int num;
    for (int i=0; i<n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    for (int i=0; i<n; i++) {
        sub_arr(i, arr[i], arr[i]);
    }

    cout << cnt << endl;

    return 0;
}
