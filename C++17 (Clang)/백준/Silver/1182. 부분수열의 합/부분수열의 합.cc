#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 21

using namespace std;

int N, S, res = 0; // S: 합
int nums[MAX];

void input(){
    cin >> N >> S;
    for (int i = 1 ; i <= N ; ++i) cin >> nums[i];
}

void DFS(int idx, int prev_sum){
    // 종료조건: 배열 끝까지 탐색 마쳤을 때.
    if (idx == N + 1){
        if (prev_sum == S) res++;
        return;
    }

    // 선택 시.
    DFS(idx + 1, prev_sum + nums[idx]);

    // [중요] 미선택 시. 현재 인덱스의 숫자를 더하지 않는 경우도 고려되어야 함. 백트래킹에 위임할 수 있음.
    DFS(idx + 1, prev_sum);
}

void solve(){
    // idx = 1부터 prev_sum = 0으로 출발
    DFS(1, 0);

    // S가 0일 경우, 아무 것도 안 뽑은 공집합도 카운트되므로 최종 결과에서 1 감산
    if (S == 0) res--;
    
    cout << res;
}

int main(){
    fastio
    input();
    solve();
    return 0;
}