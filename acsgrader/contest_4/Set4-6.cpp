#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin, str);

    const int size = str.size();
    string ans = "";
    bool id = false;
    for (int len = 1; len < size; len++) {
        string a = str.substr(0, len);
        string b = str.substr(size - len);
        if (a == b) {
            id = true;
            ans = a;
        }
    }

    if (!id) {
        cout << '0' << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}
