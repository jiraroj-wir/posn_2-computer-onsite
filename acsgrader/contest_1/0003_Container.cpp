#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    cin >> n;
    vector<int> vec;

    for (int i=0; i<n; i++) {
        cin >> num;
        vec.push_back(num);
    }

    int lower, area = 0;
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n; j++) {
            lower = (vec[i] > vec[j]) ? vec[j] : vec[i];
            if (lower * (j - i) > area) {
                area = lower * (j - i);
            }
        }
    }

    cout << area << endl;

    return 0;
}
