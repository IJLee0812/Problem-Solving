#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long n;
map<long long, long long> f; // 비효율적인 배열 대신 효율성을 위해 map 사용. n이 천억까지 가능하므로, 메모이제이션을 해야 함.

long long fibo(long long n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (f.count(n) > 0) return f[n]; // 중요!

    if (n % 2 == 0){ // 짝수일 때(n = 2k)
        long long k = n / 2;
        long long tmp1 = k + 1, tmp2 = k - 1;
        f[n] = (fibo(k) * (fibo(tmp1) + fibo(tmp2))) % MOD;
        return f[n]; // 리턴
    }

    // 홀수일 때(n = 2k + 1)
    long long k = (n - 1) / 2;
    long long tmp = k + 1;
    f[n] = ((fibo(tmp) * fibo(tmp)) + (fibo(k) * fibo(k))) % MOD;
    return f[n]; // 리턴
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    cout << fibo(n);

    return 0;
}