#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long n;

vector<vector<long long>> multiple(vector<vector<long long>> &a, vector<vector<long long>> &b){
    vector<vector<long long>> res(2, vector<long long>(2));

    for (int i = 0 ; i < 2 ; ++i)
        for (int j = 0 ; j < 2 ; ++j){
            for (int k = 0 ; k < 2 ; ++k)
                res[i][j] += a[i][k] * b[k][j];
            
            res[i][j] %= MOD;
        }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    vector<vector<long long>> ans = {{1, 0}, {0, 1}}; // 단위행렬
    vector<vector<long long>> a = {{1, 1}, {1, 0}};

    while (n > 0){
        if (n % 2 == 1)
            ans = multiple(ans, a);
        a = multiple(a, a);
        n /= 2;
    }

    cout << ans[0][1]; // == ans[1][0]

    return 0;
}