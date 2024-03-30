#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& nums) {
    int maxEndingHere = nums[0];
    int maxSoFar = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        totalSum += nums[i];
    }

    int maxKadane = kadane(nums);

    for (int i = 0; i < n; i++) {
        nums[i] = -nums[i];
    }

    int maxInverseKadane = kadane(nums);

    int maxCircular = totalSum + maxInverseKadane;

    if (maxKadane < 0) {
        cout << maxKadane << endl;
    } else {
        cout << max(maxCircular, maxKadane) << endl;
    }

    return 0;
}

