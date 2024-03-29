#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    int num;
    vector<int> nums;
    for (int i=0; i<n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    int max_profit = INT_MIN;
    for (int i=0; i<nums.size(); i++) {
        for (int j=i+1; j<nums.size(); j++) {
            max_profit = max(max_profit, nums[j] - nums[i]);
        }
    }
    cout << max_profit << endl;

    return 0;
}
