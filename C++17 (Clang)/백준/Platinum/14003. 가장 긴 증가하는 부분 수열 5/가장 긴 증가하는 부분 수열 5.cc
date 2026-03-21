#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1000005

using namespace std;

int N, A[MAX], pos[MAX]; // pos for backtracking to print out LIS
vector<int> L;

void input(){
    cin >> N;

    for (int i = 0 ; i < N ; ++i) cin >> A[i];
}

void solve(){
    for (int i = 0 ; i < N ; ++i){
        if (L.empty() || L.back() < A[i]){
            L.push_back(A[i]);
            pos[i] = L.size() - 1; // 0-index
        }

        else{
            auto it = lower_bound(L.begin(), L.end(), A[i]);
            *it = A[i];
            pos[i] = it - L.begin(); // 0-index
        }
    }

    cout << L.size() << '\n';

    vector<int> ans;
    int target_idx = L.size() - 1;

    for (int i = N - 1 ; i >= 0 ; --i){
        if (pos[i] == target_idx){
            ans.push_back(A[i]);
            target_idx--;
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto n : ans) cout << n << ' ';
}

int main(){
    fastio
    input();
    solve();    
    return 0;
}