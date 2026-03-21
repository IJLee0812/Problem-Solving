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
    
    for (int i = N ; i >= 1 ; --i){
        int tmp_max = 0;
        
        for (int j = N ; j > i ; --j) if (A[i] > A[j]) tmp_max = max(tmp_max, dp[j]);
        
        dp[i] = tmp_max + 1;      
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
    return 0;
}