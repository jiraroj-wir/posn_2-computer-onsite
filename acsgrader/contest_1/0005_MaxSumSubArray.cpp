#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, nums;
    vector<int> v;
    cin >> n;
    cin.ignore();

    for (int i=0; i<n; i++) {
        cin >> nums;
        v.push_back(nums);
    }

    int tmp = 0, ans = 0;
    for (int i=0; i<n; i++) {
        tmp = max(v.at(i), v.at(i) + tmp);
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
