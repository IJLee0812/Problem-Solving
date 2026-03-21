#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1002
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, dp[MAX], ans;
vector<int> A;

int main(){
    fastio
    cin >> N;

    int tmp;
    for (int i = 0 ; i < N ; ++i){
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0 ; i < N ; ++i){
        int tmp_max = 0;

        for (int j = 0 ; j < i ; ++j) if (A[i] < A[j]) tmp_max = max(tmp_max, dp[j]);

        dp[i] = tmp_max + 1;
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}