#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    long n; cin >> n;
    long tshirt[6];
    for (int i = 0 ; i < 6 ; ++i) cin >> tshirt[i];
    long t, p; cin >> t >> p;
    int a = 0;
    for (int i = 0 ; i < 6 ; ++i){
        if (tshirt[i] % t == 0) a += tshirt[i] / t;
        else a += tshirt[i] / t + 1;
    }
    cout << a << '\n';
    cout << n / p << ' ' << n % p << '\n';
    return 0;
}
