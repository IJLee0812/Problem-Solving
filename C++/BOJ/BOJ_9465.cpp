#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int T, n, res;
int sticker[2][MAX], dp[2][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--){
        cin >> n;

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < n; ++j)
                cin >> sticker[i][j];

        // 초기값 설정
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        if (n > 1){
            dp[0][1] = sticker[0][1] + sticker[1][0];
            dp[1][1] = sticker[1][1] + sticker[0][0];
        }

        // dp 계산
        for (int i = 2; i < n; ++i){
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
        }

        // 결과 계산
        res = max(dp[0][n - 1], dp[1][n - 1]);
        cout << res << '\n';
    }

    return 0;
}