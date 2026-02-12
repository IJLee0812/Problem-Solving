#include <iostream>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll N, A, a1, a2;

ll eea(ll a, ll b){
    if (b == 0){
        a1 = 1;
        a2 = 0;
        return a;
    }
    ll ret = eea(b, a % b);
    ll tmp = a1;
    a1 = a2;

    a2 = tmp + (-1) * a2 * (a / b);
    return ret;
}

int main(){
    fastio

    cin >> N >> A;

    cout << N - A << " ";

    if (eea(N, A) == 1) cout << (a2 % N + N) % N;
    else cout << -1;

    return 0;
}