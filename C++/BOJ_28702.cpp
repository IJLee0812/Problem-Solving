#include <bits/stdc++.h>
using namespace std;

int isnum(char c){
    return (c >= '0' && c <= '9') ? 1 : 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    string inputstr[3];
    int out;
    for (int i = 0 ; i < 3 ; i++){
        cin >> inputstr[i];
        if (isnum(inputstr[i].at(0))){
            out = stoi(inputstr[i]) + 3 - i;
            break;
        }
    } 
    if (out % 3 == 0 && out % 5 == 0) cout << "FizzBuzz";
    else if (out % 3 == 0 && out % 5 != 0) cout << "Fizz";
    else if (out % 3 != 0 && out % 5 == 0) cout << "Buzz";
    else cout << out;
    return 0;
}
