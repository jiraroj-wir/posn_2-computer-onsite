#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (b < c) swap(b, c);

    int cnt = 0;
    while (a > 0 && b > 0) {
        a--;
        b--;
        cnt++;

        if (a < b) swap(a, b);
        if (a < c) swap(a, c);
        if (b < c) swap(b, c);

        if (b == 0 && c == 0) {
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}

