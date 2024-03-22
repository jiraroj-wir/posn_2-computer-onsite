#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    getline(cin, str);

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '{' && str[i] != '}' && str[i] != '[' && str[i] != ']' && str[i] != '(' && str[i] != ')') {
            continue;
        }
        else if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            stk.push(str.at(i));
        }
        else if (!stk.empty() && str[i] == '}' && stk.top() == '{') {
            stk.pop();
        }
        else if (!stk.empty() && str[i] == ']' && stk.top() == '[') {
            stk.pop();
        }
        else if (!stk.empty() && str[i] == ')' && stk.top() == '(') {
            stk.pop();
        }
        else {
            cout << "NOT balanced" << endl;
            return 0;
        }
    }

    if (stk.empty()) {
        cout << "balanced" << endl;
    }
    else {
        cout << "NOT balanced" << endl;
    }

    return 0;
}
