#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1002

using namespace std;

int A[MAX], N, dp[MAX], ans;

int main(){
    fastio
    cin >> N;

    for (int i = 1 ; i <= N ; ++i) cin >> A[i];

    for (int i = 1 ; i <= N ; ++i){
        dp[i] = A[i];

        for (int j = 1 ; j < i ; ++j)
            if (A[i] > A[j]) dp[i] = max(dp[i], dp[j] + A[i]);

        ans = m ax(ans, dp[i]);
    }

    cout << ans;
    return 0;
}