#include <bits/stdc++.h>
using namespace std;

struct FloatComparator {
    bool operator()(const float a, const float b) const {
        return fabs(a - b) > numeric_limits<float>::epsilon() * fmax(fabs(a), fabs(b));
    }
};

float slope(pair<int, int> a, pair<int, int> b) {
    if (b.first == a.first) return numeric_limits<float>::infinity();
    return static_cast<float>(b.second - a.second) / (b.first - a.first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    int max_count = 0;
    for (int i = 0; i < n; i++) {
        map<float, int, FloatComparator> slope_count;
        int same_points = 1;
        int vertical_lines = 0;
        for (int j = i + 1; j < n; j++) {
            float m = slope(arr[i], arr[j]);
            if (m == numeric_limits<float>::infinity()) {
                vertical_lines++;
            } else {
                slope_count[m]++;
            }
        }

        for (auto& count : slope_count) {
            max_count = max(max_count, count.second + same_points);
        }
        max_count = max(max_count, vertical_lines + same_points);
    }

    cout << max_count << endl;

    return 0;
}

