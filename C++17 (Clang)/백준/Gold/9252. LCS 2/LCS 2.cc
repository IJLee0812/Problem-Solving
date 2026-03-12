#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1002

using namespace std;

string A, B;
int lenA, lenB, LCS[MAX][MAX];

vector<char> str;

void input(){
    cin >> A >> B;

    // for DP, apply 1-based indexing.
    A = " " + A;
    B = " " + B;

    lenA = A.length() - 1, lenB = B.length() - 1;
}

void get_lcs(int i, int j){
    // 종료조건.
    if (i == 0 || j == 0) return;

    // 문자가 같다면? 공통 부분 수열의 원소이므로 "정답에 넣고 대각선" 이동
    if (A[i] == B[j]){
        str.push_back(A[i]);
        get_lcs(i - 1, j - 1);
    }

    // 문자가 다르다면? 위와 왼쪽 중 "LCS 값이 더 큰 쪽"으로만 이동
    else{
        if (LCS[i - 1][j] > LCS[i][j - 1]) get_lcs(i - 1, j);
        else get_lcs(i, j - 1);
    }
}

void solve(){
    for (int i = 1 ; i <= lenA ; ++i){
        for (int j = 1 ; j <= lenB ; ++j){
            if (A[i] == B[j]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    cout << LCS[lenA][lenB] << '\n';

    if (LCS[lenA][lenB] > 0){
        get_lcs(lenA, lenB);
        reverse(str.begin(), str.end());
        for (char c : str) cout << c;
    }
}

int main(){
    fastio
    input();
    solve();
    return 0;
}