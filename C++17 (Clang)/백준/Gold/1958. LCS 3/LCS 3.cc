#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 102

using namespace std;

short LCS[2][MAX][MAX];
string A, B, C;
int lenA, lenB, lenC;

void input(){
    cin >> A >> B >> C;
    lenA = A.size(), lenB = B.size(), lenC = C.size();
    A = " " + A, B = " " + B, C = " " + C;
}

void solve(){
    for (int i = 1 ; i <= lenA ; ++i){
        int prev = (i - 1) % 2, curr = i % 2;
        for (int j = 1 ; j <= lenB ; ++j){
            for (int k = 1 ; k <= lenC ; ++k){
                if (A[i] == B[j] && B[j ]== C[k]) LCS[curr][j][k] = LCS[prev][j-1][k-1] + 1;
                else LCS[curr][j][k] = max({LCS[prev][j][k], LCS[curr][j-1][k], LCS[curr][j][k-1]});
            }
        }
    }
    // 마지막으로 계산된 층( == lenA % 2)
    cout << LCS[lenA%2][lenB][lenC];
}

int main(){
    fastio
    input();
    solve();
    return 0;
}