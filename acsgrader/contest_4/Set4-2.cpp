#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    string str_in;
    getline(cin, str_in);

    vector<string> words;
    stringstream ss(str_in);

    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    string a, b;
    getline(cin, a); getline(cin, b);

    vector<int> idx_a, idx_b;
    int idx = 0;
    for (auto w : words) {
        idx++;
        if (w == a) {
            idx_a.push_back(idx);
        }
        if (w == b) {
            idx_b.push_back(idx);
        }
    }

    int min_d = INT_MAX;
    for (auto a : idx_a) {
        for (auto b : idx_b) {
            min_d = min(min_d, abs(a - b));
        }
    }

    cout << min_d << endl;
    
    return 0;
}

