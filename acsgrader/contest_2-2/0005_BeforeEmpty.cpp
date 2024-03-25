#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str);
    size_t size = str.size();

    vector<int> a_cnt(26, 0);
    for (int i=0; i<size; i++) {
        a_cnt.at(str[i] - 'a')++;
    }

    int max_ch = *max_element(a_cnt.begin(), a_cnt.end());

    vector<char> ans;
    for (int i=size - 1; i>=0; i--) {
        if (max_ch == a_cnt.at(str[i] - 'a')) {
            ans.insert(ans.begin(), str[i]); 
            a_cnt.at(str[i] - 'a')--; 
        }
    }

    for (auto a : ans) {
        cout << a;
    }

    return 0;
}
