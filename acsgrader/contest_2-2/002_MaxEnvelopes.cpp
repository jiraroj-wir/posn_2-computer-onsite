#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> env;
int n;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int max_env(int idx, vector<int>& memo) {
    if (idx >= n) {
        return 0;
    }
    if (memo[idx] != -1) {
        return memo[idx];
    } 
    int maxCount = 1;
    for (int i = idx + 1; i < n; ++i) {
        if (env[idx].first < env[i].first && env[idx].second < env[i].second) {
            maxCount = max(maxCount, 1 + max_env(i, memo));
        }
    }
    memo[idx] = maxCount;
    return maxCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin.ignore();
    env.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> env[i].first >> env[i].second;
    }

    sort(env.begin(), env.end(), compare);

    vector<int> memo(n, -1);
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result = max(result, max_env(i, memo));
    }

    cout << result << endl;
    return 0;
}

