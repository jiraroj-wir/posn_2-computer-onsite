#include <bits/stdc++.h>
using namespace std;

int dp[55][55][55][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, g, b;
    cin >> r >> g >> b;
    dp[1][0][0][0] = 1;
    dp[0][1][0][1] = 1;
    dp[0][0][1][2] = 1;
    for (int i=0; i<=r; i++) {
        for (int j=0; j<=g; j++) {
            for (int k=0; k<=b; k++) {
                if (i-1 >=0) {
                    dp[i][j][k][0] += dp[i-1][j][k][1] + dp[i-1][j][k][2];
                }
                if (j-1 >=0) {
                    dp[i][j][k][1] += dp[i][j-1][k][0] + dp[i][j-1][k][2];
                }
                if (k-1 >= 0) {
                    dp[i][j][k][2] += dp[i][j][k-1][0] + dp[i][j][k-1][1];
                }
            } 
        }
    }
    cout << dp[r][g][b][0] + dp[r][g][b][1] + dp[r][g][b][2] << endl;

    return 0;
}
