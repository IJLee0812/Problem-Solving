#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int D(int A){
    int res = A * 2;
    if (res > 9999) return res % 10000;
    return res;
}

int S(int A){
    if (A == 0) return 9999;
    return A - 1;
}

int L(int A){
    string str = to_string(A);
    string first = str.substr(0, 1); // 맨 앞의 문자 1개 문자열로 분리
    string sub = str.substr(1, str.length() - 1); // 나머지 문자열을 문자열로 분리
    str = sub + first; // + : 문자열 concat 연산
    return stoi(str);
}

int R(int A){
    string str = to_string(A);
    string last = str.substr(str.length() - 1);
    string sub = str.substr(0, str.length() - 1);
    str = last + sub;
    return stoi(str);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while (T--){
        string command = "";
        cin >> A >> B;

        while (true){
            int res_D = D(A), res_S = S(A), res_L = L(A), res_R = R(A);

            // - - - 종료조건 - - -
            if (res_D == B){
                command += 'D';
                break;
            }
            else if (res_S == B){
                command += 'S';
                break;
            }
            else if (res_L == B){
                command += 'L';
                break;
            }
            else if (res_R == B){
                command += 'R';
                break;
            }
            // - - - - - - - - - -

            int diff_D = abs(res_D - B), diff_S = abs(res_S - B), diff_L = abs(res_L - B), diff_R = abs(res_R - B), min_res;
            
            min_res = min({diff_D, diff_S, diff_L, diff_R});
            if (min_res == diff_D){
                command += 'D';
                A = res_D;
            }
            else if (min_res == diff_S){
                command += 'S';
                A = res_S;
            }
            else if (min_res == diff_L){ 
                command += 'L';
                A = res_L;
            }
            else{ 
                command += 'R';
                A = res_R;
            }
        }
        
        cout << command << '\n';
    }

    return 0;
}
