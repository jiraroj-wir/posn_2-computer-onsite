#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    queue<int> q;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    cout << q.front() << endl;

    return 0;
}
