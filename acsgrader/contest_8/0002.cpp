#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e10+7;
    
int p[200];

void cp() {
    p[0] = 0;
    for (int i=1; i<200; i++) {
        p[i] = p[i-1] + i;
    }
}

int ps(int n) {
    if (n > 199) {
        return (n*(n+1))/2;
    }
    return p[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);

    cp();
    int cnt = 0;
    ll sum = 0;
    for (int i=0; i<=str.size(); i++) {
        if (cnt >= 0 && str[i] == '1') {
            cnt++;
        }
        else if (cnt > 0 && str[i] != '1') {
            sum+=ps(cnt);
            sum%=MOD;
            cnt = 0;
        }
        else {
            cnt = 0;
        }
    }

    cout << sum << endl;

    return 0;
}
