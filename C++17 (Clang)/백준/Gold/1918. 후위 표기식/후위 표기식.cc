#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str; cin >> str;
    stack<char> s;

    for (char ch : str){
        if (ch >= 'A' && ch <= 'Z'){
            cout << ch;
            continue;
        }

        if (ch == '(')
            s.push(ch);
        else if (ch == ')'){
            while (!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if (ch == '*' || ch == '/'){
            while (!s.empty() && (s.top() == '*' || s.top() == '/')){
                cout << s.top();
                s.pop();
            }
            s.push(ch);
        }
        else if (ch == '+' || ch == '-'){
            while (!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}
