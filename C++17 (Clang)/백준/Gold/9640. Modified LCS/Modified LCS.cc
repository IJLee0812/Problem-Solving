#include <iostream>
#include <string>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef unsigned long long ull;
typedef unsigned __int128 u128;

// 확장 유클리드 호제법 (a*x + b*y = gcd)
long long ext_gcd(long long a, long long b, long long &x, long long &y){
    if (b == 0){
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long d = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

ull lcm(ull a, ull b, ull g){
    return (a / g) * b;
}

void print_u128(u128 n){
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

    if (f1 > f2){
        swap(n1, n2);
        swap(f1, f2);
        swap(d1, d2);
    }

    long long diff = f2 - f1;
    long long x, y;
    long long g = ext_gcd(d1, d2, x, y);

    // 두 시작점의 차이가 최대공약수의 배수가 아니면 절대 만나지 않음
    if (diff % g != 0){
        cout << 0 << "\n";
        return;
    }

    // 첫 번째 공통 원소 계산 (모듈러 연산)
    long long mod = d2 / g;
    long long k1 = (x % mod) * ((diff / g) % mod) % mod;
    k1 = (k1 % mod + mod) % mod;

    u128 first_common = (u128)f1 + (u128)k1 * d1;
    u128 d_common = lcm(d1, d2, g);
    u128 max_f = max(f1, f2);
    
    if (first_common < max_f){
        u128 gap = max_f - first_common;
        u128 step = (gap + d_common - 1) / d_common;
        first_common += step * d_common;
    }

    u128 max1 = (u128)f1 + (u128)(n1 - 1) * d1;
    u128 max2 = (u128)f2 + (u128)(n2 - 1) * d2;
    u128 limit = max1 < max2 ? max1 : max2;

    if (first_common > limit){
        cout << 0 << "\n";
    }
    else{
        u128 count = (limit - first_common) / d_common + 1;
        print_u128(count);
    }
}

int main(){
    fastio    
    int t;
    if (cin >> t){
        while (t--) solve();
    }
    return 0;
}