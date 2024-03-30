#include <bits/stdc++.h>
#include <climits>
#define ll long long int
const ll INF = LLONG_MAX;
using namespace std;

ll min_coin(ll N, ll target, vector<ll>& coins)
{
    vector<ll> DP(target + 1, INF);
    DP[0] = 0;

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < N; j++) {
            if (coins[j] > i || DP[i - coins[j]] == INF) {
                continue;
            }
            DP[i] = min(DP[i], DP[i - coins[j]] + 1);
        }
    }
    if (DP[target] != INF)
        return DP[target];

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    ll N, target, num;
    cin >> N >> target;

    vector<ll> coins;
    for (int i=0; i<N; i++) {
        cin >> num;
        coins.push_back(num);
    }
    
    cout << min_coin(N, target, coins) << endl;
}
