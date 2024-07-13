#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, res = 0 ; cin >> N >> M;
    string S; cin >> S;

    string temp = "IO", PN = "";

    for (int i = 0 ; i < N ; ++i)
        PN.append(temp);
    
    PN.append("I");

    for (int i = 0 ; i < S.size() ; ++i){
        if (S[i] == 'I'){
            temp = "";
            for (int j = i ; j < i + (2 * N + 1) ; ++j)
                temp += S[j];
            if (temp.compare(PN) == 0) res++;
        }  
    }

    cout << res << '\n';
    
    return 0;
}