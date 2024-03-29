#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    cin.ignore();

    vector<int> nums(N);
    vector<int> missing;
    for (int i=0; i<10000; i++) {
        missing.push_back(i);
    }

    for (int i=0; i<N; i++) {
        cin >> nums[i]; 
        missing.erase(remove(missing.begin(), missing.end(), nums[i]), missing.end());
    }

    int min_n = nums[0];
    int cnt = 0;
    int idx = 0;
    while(cnt <= K) {
        if (missing[idx] > min_n) {
            if (cnt == K-1) {
                cout << missing[idx] << endl;
                return 0;
            }
            cnt++;
        } 
        idx++;
    }
}
