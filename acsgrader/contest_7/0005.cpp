#include <bits/stdc++.h>
using namespace std;

string longest_str = "";
vector<int> parse_str(const string& str) {
    vector<int> numbers;
    stringstream ss(str);
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }

    return numbers;
}

void find_A(const vector<int>& nums) {
    int n = nums.size();
    for (int i=0; i<n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diff = nums[j] - nums[i];
            int count = 2;
            int lastNum = nums[j];
            string sequence = to_string(nums[i]) + " " + to_string(nums[j]);

            for (int k=j+1; k<n; ++k) {
                if (nums[k] - lastNum == diff) {
                    sequence += " " + to_string(nums[k]);
                    lastNum = nums[k];
                    count++;
                }
            }

            if (count >= 3) {
                if (sequence.size() > longest_str.size()) {
                    longest_str = sequence;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    string str;
    getline (cin, str);

    vector<int> nums = parse_str(str);
    find_A(nums);

    int cnt = 0;
    //cout << longest_str << endl;
    for (int i=0; i<longest_str.size(); i++) {
        if (longest_str[i] == ' ') {
            cnt++;
        }
    }

    cout << cnt + 1 << endl;

    return 0;
}

