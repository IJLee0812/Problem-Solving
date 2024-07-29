#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int n, tri[MAX][MAX], dp[MAX][MAX], res = 0; // 삼각형 구조 : 1차원 배열 X. 2차원 배열을 이용하면 쉬움.

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= i ; ++j)
            cin >> tri[i][j];
        
    dp[1][1] = tri[1][1];

    for (int i = 2 ; i <= n ; ++i)
        for (int j = 1 ; j <= i ; ++j)
            dp[i][j] = tri[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]); // dp[i - 1][j - 1] : 왼쪽 위, dp[i - 1][j] : 오른쪽 위
        
    for (int i = 1 ; i <= n ; ++i)
        if (res < dp[n][i]) res = dp[n][i];
    
    cout << res;
    return 0;
}
