#include <iostream>
#include <cmath>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    
    // 문제 4
    int N, res = 1; cin >> N;
    while(2*res <= N) res *= 2;
    cout << res << endl;

    // 실수 비교 문제
    double a = 0.1 + 0.1 + 0.1;
    double b = 0.3;
    if (a == b) cout << "same 1\n";
    if (abs(a-b) < 1e-12) cout << "same 2\n"; // 두 실수가 같은지 알고 싶을 때는 둘의 차이가 아주 작은 값, 대략 10^-12 이하면 동일하다고 처리하는 것이 안전하다.

    return 0;
}



