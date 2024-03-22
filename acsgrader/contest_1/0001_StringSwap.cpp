#include <bits/stdc++.h>
using namespace std;

string str1, str2, ch1[2], ch2[2];
int d = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> str1 >> str2;
    
    if (str1 == str2) {
        cout << "true" << endl;
        goto END;
    }
    if (str1.size() == str2.size()) {
        for (int i=0; i<str1.size(); i++) {
            if (str1[i] != str2[i]) {
                d++;
                if (d <= 2) {
                    ch1[d-1].push_back(str1[i]);
                    ch2[d-1].push_back(str2[i]);
                }
                else {
                    cout << "false" << endl;
                    goto END;
                }
            }
        }
        if (2 == d) {
            if (ch1[0] == ch2[1] && ch1[1] == ch2[0]) {
                cout << "true" << endl;
            }
        }
        else {
            cout << "false" << endl;
            goto END;
        }
    }
    else {
        cout << "false" << endl;
        goto END;
    }

    END:
    return 0;
}
