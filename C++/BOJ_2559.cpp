#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int res = INT_MIN;

int temp, sum[100001], N, K;

int main(){
    cin >> N >> K;

    for (int i = 1 ; i <= N ; ++i){
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }

    for (int i = K ; i <= N ; ++i)
        res = max(res, sum[i] - sum[i - K]);
    
    cout << res;
}