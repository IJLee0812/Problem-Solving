#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str; cin >> str;

    stack<char> s;

    for (char ch : str){
        if (ch >= 'A' && ch <= 'Z'){
            cout << ch; // 그냥 출력
            continue;
        }


        if (ch == '(') // CASE 1
            s.push(ch);

        else if (ch == ')'){ // CASE 2
            while (!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop(); // '(' 제거
        }

        else if (ch == '*' || ch == '/'){ // CASE 3
            while (!s.empty() && (s.top() == '*' || s.top() == '/')){
                cout << s.top();
                s.pop();
            }
            s.push(ch); // 먼저 들어왔던 *, /이 다 출력&삭제된 다음 push
        }

        else if (ch == '+' || ch == '-'){ // CASE 4
            while (!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.push(ch);
        }
        
    }

    while (!s.empty()){ // 스택에 남아있는 원소들도 모두 출력해야 함
        cout << s.top();
        s.pop();
    }

    return 0;
}
