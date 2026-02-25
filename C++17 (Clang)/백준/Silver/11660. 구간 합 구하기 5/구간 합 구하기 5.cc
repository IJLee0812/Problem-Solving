#include <iostream>
#define MAX 1025
using namespace std;

int arr[MAX][MAX], dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;

    for (int i = 1 ; i <= N ; ++i){
        for (int j = 1 ; j <= N ; ++j){
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }

    int x1, y1, x2, y2, res;

    while (M--){
        cin >> x1 >> y1 >> x2 >> y2;

        res = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout << res << '\n';
    }

    return 0;
}