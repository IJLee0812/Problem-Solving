#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1002
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string a, b;
vector<string> A, B;
int LCS[MAX][MAX];

void input(){
    cin >> a >> b;

    // 한글은 3바이트 취급하므로, i를 3씩 증가시키며 3칸씩 substr로 잘라넣으면 풀림(덩어리끼리 비교하므로 한글 비교 가능)
    for (int i = 0 ; i < a.length() ; i += 3) A.push_back(a.substr(i, 3));
    for (int i = 0 ; i < b.length() ; i += 3) B.push_back(b.substr(i, 3));
}

void solve(){
    int as = A.size(), bs = B.size();

    for (int i = 1 ; i <= as ; ++i){
        for (int j = 1 ; j <= bs ; ++j){
            if (A[i-1] == B[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1;
            else LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
        }
    }

    cout << LCS[as][bs];
}

int main(){
    fastio
    input();
    solve();
    return 0;
}