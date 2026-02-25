#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, res = 0, cnt;
    string S;

    cin >> N >> M >> S;

    for (int i = 0 ; i < S.size() ; ++i){
        cnt = 0;
        if (S[i] == 'I'){
            while (S[i + 1] == 'O' && S[i + 2] == 'I'){
                cnt++;
                i += 2;
                
                if (cnt == N){ 
                    cnt--; 
                    res++;
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}
