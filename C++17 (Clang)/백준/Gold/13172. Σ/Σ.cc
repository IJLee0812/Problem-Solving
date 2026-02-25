#include <iostream>

using namespace std;

typedef long long ll;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int M;
ll X = 1'000'000'007;

ll gcd(ll a, ll b){
    while (b != 0){
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

ll power(ll a, ll b){
    ll result = 1;

    while (b > 0){
        if (b % 2 == 1) result = (result * a) % X;
        a = (a * a) % X;
        b /= 2;
    }

    return result;
}

// FLT: N^(P-1) <=> 1 (mod P)
// n^(-1) mod X <=> n^(X - 2) mod X
ll mod_inverse(ll N){
    return power(N, X - 2);
}

int main(){
    fastio
    cin >> M;

    ll E = 0;

    for (int i = 0 ; i < M ; ++i){
        ll N, S;
        cin >> N >> S;

        ll common = gcd(N, S);
        N /= common; S /= common;

        ll term = (S * mod_inverse(N)) % X;
        E = (E + term) % X;
    }

    cout << E;
    return 0;
}