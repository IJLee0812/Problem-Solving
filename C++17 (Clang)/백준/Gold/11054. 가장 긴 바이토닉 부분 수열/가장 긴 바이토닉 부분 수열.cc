#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1002 
using namespace std;

int A[MAX], N, lis[MAX], lds[MAX];

int main(){
    fastio
    cin >> N;

    for (int i = 1 ; i <= N ; ++i) cin >> A[i];

    // 순방향(왼->오) LIS
    for (int i = 1 ; i <= N ; ++i){
        int lis_max = 0;

        for (int j = 1 ; j < i ; ++j) if (A[i] > A[j]) lis_max = max(lis_max, lis[j]);

        lis[i] = lis_max + 1;
    }

    // 역방향(오->왼) LDS
    for (int i = N ; i >= 1 ; --i){
        int lds_max = 0;

        for (int j = N ; j > i ; --j) if (A[i] > A[j]) lds_max = max(lds_max, lds[j]);

        lds[i] = lds_max + 1;
    }

    int ans = 0;
    for (int i = 1 ; i <= N ; ++i){
        int comp = lis[i] + lds[i] - 1;
        ans = max(ans, comp);
    }

    cout << ans;

    return 0;
}