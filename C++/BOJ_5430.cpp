#include <bits/stdc++.h>
using namespace std;

void solve(string functions, int nums, int *intnumarr){
    int left_idx = 0, right_idx = 0;
    bool reverse = false;

    for (int i = 0 ; i < functions.size() ; ++i){
        if (functions[i] == 'R'){
            if (reverse) reverse = false;
            else reverse = true;
        }
        else{
            if (reverse) right_idx++;
            else left_idx++;
        }
    }

    if (nums - (left_idx + right_idx) < 0){
        cout << "error\n";
        return;
    }

    cout << '[';
    if (reverse){
        for (int i = nums - right_idx - 1 ; i >= left_idx ; --i){
            cout << intnumarr[i];
            if (i != left_idx) cout << ',';
        }
    }
    else{
        for (int i = left_idx ; i < nums - right_idx ; ++i){
            cout << intnumarr[i];
            if (i != nums - (right_idx + 1)) cout << ',';
        }
    }
    cout << "]\n";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    string functions;
    int nums;
    string numarr;

    while (T--){
        cin >> functions >> nums >> numarr;

        string temp = "";
        int intnumarr[nums], idx = 0;

        for (int i = 1 ; i < numarr.size() ; ++i){
            if (isdigit(numarr[i]))
                temp += numarr[i];
            else if (numarr[i] == ',' || numarr[i] == ']')
                if (!temp.empty()){
                    intnumarr[idx++] = stoi(temp);
                    temp = "";
                }
        }

        solve(functions, nums, intnumarr);

    }

    return 0;
}
