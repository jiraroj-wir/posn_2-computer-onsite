#include <bits/stdc++.h>
#include <cstring>
using namespace std;

vector<int> ch(26, 0);

bool is_odd(int n) {
    if ((n & 1) == 1) {
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);

    for (int i=0; i<str.size(); i++) {
        ch[str[i] - 'a']++;
    }

    int cnt = 0;
    for (int i=0; i<26; i++) {
        if (is_odd(ch[i])) {
            cnt++;
        }
        if (cnt == 1 && !is_odd(str.size())) {
            cout << 'N' << endl;
            return 0;
        }
        if (cnt == 2 && is_odd(str.size())) {
            cout << 'N' << endl;
            return 0;
        }
    }
    cout << 'Y' << endl;

    return 0;
}
