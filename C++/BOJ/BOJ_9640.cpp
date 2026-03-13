#include <iostream>
#include <string>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef unsigned long long ull;
typedef unsigned __int128 u128;

ull gcd(ull a, ull b){
    return b == 0 ? a : gcd(b, a % b);
}

ull lcm(ull a, ull b){
    return (a / gcd(a, b)) * b;
}

void print_u128(u128 n) {
    if (n == 0){
        cout << 0 << "\n";
        return;
    }

    string s;
    while (n > 0){
        s += (char)('0' + (n % 10)); 
        n /= 10;
    }

    reverse(s.begin(), s.end()); 
    cout << s << "\n";
}

void solve(){
    ull n1, f1, d1, n2, f2, d2;
    cin >> n1 >> f1 >> d1 >> n2 >> f2 >> d2;

    ull c1 = f1, c2 = f2;
    
    while (c1 != c2){
        if (c1 < c2){
            ull step = (c2 - c1 + d1 - 1) / d1; 
            c1 += step * d1;
        } 
        else{
            ull step = (c1 - c2 + d2 - 1) / d2;
            c2 += step * d2;
        }
    }

    ull first_common = c1;
    ull d_common = lcm(d1, d2);

    u128 max1 = (u128)f1 + (u128)(n1 - 1) * d1;
    u128 max2 = (u128)f2 + (u128)(n2 - 1) * d2;
    
    u128 limit = max1 < max2 ? max1 : max2;

    if ((u128)first_common > limit) cout << 0 << "\n";
    else{
        u128 count = (limit - first_common) / d_common + 1;
        print_u128(count);
    }
}

int main() {
    fastio    
    int t;
    if (cin >> t) while (t--) solve();
    return 0;
}