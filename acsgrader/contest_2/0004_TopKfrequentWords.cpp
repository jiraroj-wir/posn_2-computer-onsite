#include <bits/stdc++.h>
using namespace std;

bool word_in_pairs(const vector<pair<string, int>>& v, const string& word) {
    for (const auto& pair : v) {
        if (pair.first == word) {
            return true;
        }
    }
    return false;
}
bool sort_na(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    string str;
    getline(cin, str);

    size_t i = 0;
    int idx = 0;
    vector<pair<string, int>> v;
    string temp;
    while (i <= str.length()) {
        if (i < str.length() && str.at(i) != ' ') {
            temp += str.at(i);
        } 
        else {
            if (!word_in_pairs(v, temp) && !temp.empty()) {
                v.push_back(make_pair(temp, idx));
                v.at(idx).second = 0;
                idx++;
            }
            else {
                for (int i=0; i<v.size(); i++) {
                    if (v.at(i).first == temp) {
                        v.at(i).second += 1;
                    }
                }
            }
            temp.clear();
        }
        i++;
    }

    sort(v.begin(), v.end(), sort_na);

    for (int j = 0; j < min(n, (int)v.size()); j++) {
        cout << v[j].first << ' ' << v[j].second + 1 << ' ';
    }

    return 0;
}
