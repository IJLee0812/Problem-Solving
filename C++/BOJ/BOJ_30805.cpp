#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int N, M;
vector<int> A, B;

void input(){
    cin >> N;
    A.resize(N);
    for (int i = 0 ; i < N ; ++i) cin >> A[i];

    cin >> M;
    B.resize(M);
    for (int i = 0 ; i < M ; ++i) cin >> B[i];
}

void solve(){
    vector<int> sol;

    int a_idx = 0, b_idx = 0;

    while (a_idx < N && b_idx < M){
        int max_val = -1, next_a = -1, next_b = -1;

        // 100 ~ 1까지 큰 숫자부터 우선적으로 양쪽에 있는지 그리디
        for (int v = 100 ; v >= 1 ; --v){
            int tmp_a = -1, tmp_b = -1;

            for (int i = a_idx ; i < N ; ++i){
                if (A[i] == v){
                    tmp_a = i;
                    break;
                }
            }

            for (int i = b_idx ; i < M ; ++i){
                if (B[i] == v){
                    tmp_b = i;
                    break;
                }
            }

            // 양쪽 모두 해당 숫자 존재 시 갱신
            if (tmp_a != -1 && tmp_b != -1){
                max_val = v;
                next_a = tmp_a;
                next_b = tmp_b;
                break;
            }
        }

        // 종료조건(공통숫자 X)
        if (max_val == -1) break;

        sol.push_back(max_val);

        // 탐색위치 업데이트
        a_idx = next_a + 1;
        b_idx = next_b + 1;
        
    }

    cout << sol.size() << '\n';
    for (int num : sol) cout << num << ' ';
}

int main(){
    fastio
    input();
    solve();
    return 0;
}