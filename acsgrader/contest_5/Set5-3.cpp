#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, target;
    cin >> N >> target;
    cin.ignore();

    int arr[N];
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    if (N < 3) {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            for (int k=j+1; k<N; k++) {
                if (arr[i] + arr[j] + arr[k] < target) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
