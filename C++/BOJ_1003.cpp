#include <bits/stdc++.h>
using namespace std;

long long zeros[41], ones[41];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T, N; cin >> T;

    for (int i = 0 ; i < T ; ++i){
        cin >> N;

        fill(zeros, zeros + N, 0);
        fill(ones, ones + N, 0);

        zeros[0] = 1, zeros[1] = 0, zeros[2] = 1; 
        ones[0] = 0, ones[1] = 1;

        for (int i = 3 ; i <= N ; ++i) zeros[i] = zeros[i - 1] + zeros[i - 2];

        for (int i = 2 ; i <= N ; ++i) ones[i] = ones[i - 1] + ones[i - 2];

        cout << zeros[N] << ' ' << ones[N] << '\n';   
        
    }

    return 0;
}
