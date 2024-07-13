// 부족했던 부분 : 굳이 숫자를 int 자료형으로 변환하지 않고, char 단위로 string에 append하는 방식으로 생각하면 됐음. 

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    string str; cin >> str;
    int result = 0;
    string num = "";
    bool isMinus = false;
    for (int i = 0 ; i <= str.size() ; ++i){ //
        if (str[i] == '-' || str[i] == '+'||i == str.size()){
            if (isMinus){
                result -= stoi(num);
                num = "";
            }
            else{
                result += stoi(num);
                num = "";
                isMinus = false;
            }
        }
        else num += str[i];
        if (str[i] == '-') isMinus = true;
    }
    cout << result << '\n';
    return 0;
}
