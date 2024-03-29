#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    vector<int> cite(n);
    for (int i=0; i<n; i++) {
        cin >> cite[i];
    }

    sort(cite.begin(), cite.end());

    for (int i=n; i>=0; i--) {
        int cnt = 0;
        for (auto a : cite) {
            if (a >= i) {
                cnt++;
            }
        }

        if (cnt >= i) {
            cout << i << endl;
            return 0;
        }
    }
}
