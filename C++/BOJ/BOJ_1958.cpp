#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 102
using namespace std;

string A, B, C;

int lenA, lenB, lenC;

int LCS[MAX][MAX][MAX];

void input(){
    cin >> A >> B >> C;

    A = " " + A, B = " " + B, C = " " + C;

    lenA = A.size() - 1, lenB = B.size() - 1, lenC = C.size() - 1;
}

void solve(){
    for (int i = 1 ; i <= lenA ; ++i){
        for (int j = 1 ; j <= lenB ; ++j){
            for (int k = 1 ; k <= lenC ; ++k){
                if (A[i] == B[j] && B[j] == C[k]) LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;
                else LCS[i][j][k] = max({LCS[i - 1][j][k], LCS[i][j - 1][k], LCS[i][j][k - 1]});
            }
        }
    }

    cout << LCS[lenA][lenB][lenC];
}

int main(){
    fastio
    input();
    solve();
    return 0;
}