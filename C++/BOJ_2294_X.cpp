#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

bool c(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end(), c);
    vector<int> D(k + 1, INT_MAX);
    D[0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= coins[j] && D[i - coins[j]] + 1 < D[i])
                D[i] = D[i - coins[j]] + 1;
        }
    }
    if (D[k] == INT_MAX)
        cout << -1;
    else
        cout << D[k];
    return 0;
}
