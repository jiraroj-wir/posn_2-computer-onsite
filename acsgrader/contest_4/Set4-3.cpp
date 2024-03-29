#include <bits/stdc++.h>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, Na, Nb, n;
    cin >> k >> Na >> Nb;
    cin.ignore();

    vector<int> a, b;
    for (int i=0; i<Na; i++) {
        cin >> n;
        a.push_back(n);
    }
    for (int i=0; i<Nb; i++) {
        cin >> n;
        b.push_back(n);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<tuple <int, int, int>> lk;
    for (auto i : a) {
        for (auto j : b) {
            lk.push_back(make_tuple(i, j, i+j));
        }
    }

    sort(lk.begin(), lk.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<2>(a) < get<2>(b);
    });

    int cnt = 0;
    for (auto &[a, b, sum] : lk) {
        cnt++;
        if (cnt > k) {
            break;
        }
        cout << a << ' ' << b << ' ';
    }
    return 0;
}
