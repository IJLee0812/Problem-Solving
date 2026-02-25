#include <iostream>
#include <vector>
#include <string>

using namespace std;

string input_str, bomb;

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void input(){
    cin >> input_str >> bomb;
}

void solve(){
    string result_str = "";

    int bomb_length = bomb.length();

    for (int i = 0 ; i < input_str.length() ; ++i){
        result_str += input_str[i];

        if (result_str.length() >= bomb_length){
            bool flag = true;

            // 결과 문자열의 끝부분이 폭발 문자열과 일치하는지 확인
            for (int j = 0 ; j < bomb_length ; ++j){
                if (result_str[result_str.length() - bomb_length + j] != bomb[j]){
                    flag = false;
                    break;
                }
            }

            if (flag) result_str.erase(result_str.length() - bomb_length, bomb_length);
        }

    }

    if (result_str.empty()) cout << "FRULA";
    else cout << result_str;
}

int main(){
    fastio();
    input();
    solve();
    return 0;
}   