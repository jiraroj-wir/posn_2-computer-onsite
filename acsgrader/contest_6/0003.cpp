#include <bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;
#define vii vector<pair<int, int>>

int min_room(vii& tl) {
    sort(tl.begin(), tl.end());
    priority_queue<int, vector<int>, greater<int>> lines;

    for (const auto& i : tl) {
        if (!lines.empty() && i.first >= lines.top()) {
            lines.pop();
        }
        lines.push(i.second);
    }

    return lines.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    int a, b;
    vii tl;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        tl.push_back(make_pair(a, b));
    }

    cout << min_room(tl) << endl;

    return 0;
}
