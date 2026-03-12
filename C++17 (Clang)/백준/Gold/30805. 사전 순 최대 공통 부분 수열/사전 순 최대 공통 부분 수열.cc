#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int N, M;
vector<int> A, B, ans;

void input(){
    cin >> N;
    A.resize(N);
    for (int i = 0 ; i < N ; ++i) cin >> A[i];

    cin >> M;
    B.resize(M);
    for (int i = 0 ; i < M ; ++i) cin >> B[i];
}

void solve(){
    while (!A.empty() && !B.empty()){
        // 각 배열의 최댓값을 가리키는 iterator 찾기
        // 주의: 최댓값 여러 개면, 가장 앞에 있는 것 찾음 
        auto max_a = max_element(A.begin(), A.end());
        auto max_b = max_element(B.begin(), B.end());

        // 최댓값이 같을 때
        if (*max_a == *max_b){
            ans.push_back(*max_a);

            // 인덱스 + 1 업데이트 (최댓값까지 포함해서 그 앞의 원소 전부 삭제)
            A.erase(A.begin(), max_a + 1);
            B.erase(B.begin(), max_b + 1);
        }

        // A의 최댓값이 더 클 때
        else if (*max_a > *max_b) A.erase(max_a);
        else B.erase(max_b);
    }

    cout << ans.size() << '\n';
    for (int n : ans) cout << n << ' ';
}

int main(){
    fastio
    input();
    solve();
}