#include <bits/stdc++.h>
using namespace std;

int f_move(set<pair<int, int>>& point, bool is_row) {
    vector<int> values;
    for (const auto& p : point) {
        values.push_back(is_row ? p.first : p.second);
    }
    sort(values.begin(), values.end());
    int median = values[values.size() / 2];
    int moves = 0;
    for (int val : values) {
        moves += abs(val - median);
    }

    return moves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    cin.ignore();
    set<pair<int, int>> point;

    int in;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> in;
            if (in == 1) {
                point.insert({i, j});
            }
        }
    }

    int ans = f_move(point, true) + f_move(point, false);

    cout << ans << endl;

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int f_move(int n, int m, set<pair<int, int>> point) {
    int moves = 0;
    for (auto p : point) {
        moves += abs(p.first - n);
        moves += abs(p.second - m);
    }

    return moves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    cin.ignore();
    set<pair<int, int>> point;

    int in;
    int i_min = INT_MAX, j_min = INT_MAX;
    int i_max = INT_MIN, j_max = INT_MIN;
    for (int i = 0; i < n; i++) { // row
        for (int j = 0; j < m; j++) { // column
            cin >> in;
            if (in == 1) {
                point.insert(make_pair(i, j));
                i_min = min(i_min, i);
                j_min = min(j_min, j);
                i_max = max(i_max, i);
                j_max = max(j_max, j);
            }
        }
    }

    int ans = INT_MAX;
    for (int i=i_min; i<=i_max; i++) {
        for (int j=j_min; j<=j_max; j++) {
            //if (point.find(make_pair(i, j)) != point.end()) {
                //continue;
            //} 
            ans = min(f_move(i, j, point), ans);
        }
    }

    cout << ans << endl;

    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

pair<int, int> find_centroid(set<pair<int, int>>& point) {
    if (point.empty()) return {-1, -1};

    long long sum_x = 0, sum_y = 0;
    for (const auto& p : point) {
        sum_x += p.first;
        sum_y += p.second;
    }
    int centroid_x = sum_x / point.size();
    int centroid_y = sum_y / point.size();

    return {centroid_x, centroid_y};
}

int f_move(int n, int m, set<pair<int, int>> point) {
    int moves = 0;
    for (auto p : point) {
        moves += abs(p.first - n);
        moves += abs(p.second - m);
    }

    return moves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, in;
    cin >> n >> m;
    cin.ignore();
    set<pair<int, int>> point;

    for (int i = 0; i < n; i++) { // row
    for (int j = 0; j < m; j++) { // column
        cin >> in;
        if (in == 1) {
            point.insert(make_pair(i, j));
        }
    }
}
    
    pair<int, int> centroid = find_centroid(point);
    
    int ans = INT_MAX;
    ans = min(ans, f_move(centroid.first-1, centroid.second+1, point));
    ans = min(ans, f_move(centroid.first, centroid.second+1, point));
    ans = min(ans, f_move(centroid.first+1, centroid.second+1, point));
    ans = min(ans, f_move(centroid.first-1, centroid.second, point));
    ans = min(ans, f_move(centroid.first, centroid.second, point));
    ans = min(ans, f_move(centroid.first+1, centroid.second, point));
    ans = min(ans, f_move(centroid.first-1, centroid.second-1, point));
    ans = min(ans, f_move(centroid.first, centroid.second-1, point));
    ans = min(ans, f_move(centroid.first+1, centroid.second-1, point));

    cout << ans << endl;

    return 0;
} */
