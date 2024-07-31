#include <bits/stdc++.h>
#define MAX 1025
using namespace std;

int N, M, x1, y1_, x2, y2, arr[MAX][MAX], dp[MAX][MAX], res; // y1 : <math.h> 헤더에 정의되어 있어서 재정의 문제 발생 -> y1_로 수정

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1 ; i <= N ; ++i){
        for (int j = 1 ; j <= N ; ++j){
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }

    while (M--){
        cin >> x1 >> y1_ >> x2 >> y2;
        res = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1_ - 1] + dp[x1 - 1][y1_ - 1];
        cout << res << '\n';
    }

    return 0;
}