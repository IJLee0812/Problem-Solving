#include <bits/stdc++.h>
using namespace std;

int A[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, L = 0, R = 0, cnt = 0, sum = 0; 
    cin >> N >> M;

    for (int i = 0 ; i < N ; ++i) cin >> A[i];

    while(R <= N){
        if (sum < M){
            if (R < N) sum += A[R];
            R++;
        }
        else if (sum > M){
            sum -= A[L];
            L++;
        }
        else{
            cnt++;
            sum -= A[L];
            L++;
        }   
    }

    cout << cnt << '\n';

    return 0;
}