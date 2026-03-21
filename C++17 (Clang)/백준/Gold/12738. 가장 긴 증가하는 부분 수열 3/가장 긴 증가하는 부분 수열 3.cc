#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1000005

using namespace std;

int A[MAX], N, ans;

int main(){
    fastio
    cin >> N;

    for (int i = 0 ; i < N ; ++i) cin >> A[i];

    vector<int> L;

    for (int i = 0 ; i < N ; ++i){
        if (L.empty() || L.back() < A[i]) L.push_back(A[i]);
        
        else{
            auto it = lower_bound(L.begin(), L.end(), A[i]); // 크거나 같은 위치
            *it = A[i];
        }
    }

    cout << L.size();
    return 0;
}