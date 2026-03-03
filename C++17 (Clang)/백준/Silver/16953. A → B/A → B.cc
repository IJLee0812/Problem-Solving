#include <iostream>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    fastio

    int A, B; cin >> A >> B;

    int count = 1; // 결과값 + 1. 1부터 시작.

    while (B > A){
        // 일의 자리가 1인 경우
        if (B % 10 == 1) B /= 10;
        
        // 짝수인 경우
        else if (B % 2 == 0) B /= 2;
        
        // 일의 자리가 1이 아니고, 홀수인 경우, A가 될 수 없으므로 탈출
        else break;

        count++;
    }

    if (B == A) cout << count;
    else cout << -1;

    return 0;
}