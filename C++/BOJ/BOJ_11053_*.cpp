#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

/* 오류 코드
int N, seq[MAX], D[MAX];
int main(){
    cin >> N;
    for (int i = 1 ; i < N+1 ; ++i)
        cin >> seq[i];
    int MAXV = 0;
    for (int i = 1 ; i < N+1 ; ++i){
        for (int j = 0 ; j < i ; ++j){
            if (seq[i] > seq[j])
                MAXV = max(MAXV, D[j]);
            D[i] = MAXV + 1;
        }
    }
    MAXV = 0;
    for (int i = 0 ; i < N+1 ; ++i)
        if (MAXV < D[i]) MAXV = D[i];
    cout << MAXV << endl;
    return 0;
}
*/
int N, seq[MAX], D[MAX];
int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> seq[i];
    for (int i = 1; i <= N; ++i) {
        D[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (seq[i] > seq[j])
                D[i] = max(D[i], D[j] + 1); // D[i]보다 작은 것 중 가장 큰 값 + 1
        }
    }
    int MAXV = 0;
    for (int i = 1; i <= N; ++i) // DP 배열에서 최댓값 찾는 알고리즘
        MAXV = max(MAXV, D[i]);
    cout << MAXV;
    return 0;
}
