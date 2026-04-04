#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 10002

using namespace std;

vector<pair<int, int>> Graph[MAX];

int N, M, A, B, C, start_loc, end_loc;

int max_weight = 0; // 입력받은 다리 중 가장 큰 중량 기록

void input(){
    cin >> N >> M;

    for (int i = 0 ; i < M ; ++i){
        cin >> A >> B >> C;

        Graph[A].push_back({B, C});
        Graph[B].push_back({A, C});
        max_weight = max(max_weight, C); // 이분탐색 right 범위기록
    }

    cin >> start_loc >> end_loc;
}

bool BFS(int target_weight){
    queue<int> myqueue;
    vector<bool> visited(N + 1, false);

    myqueue.push(start_loc);
    visited[start_loc] = true;

    while (!myqueue.empty()){
        int curr = myqueue.front();

        myqueue.pop();

        // 도착가능 리턴
        if (curr == end_loc) return true;

        for (const auto& next_island : Graph[curr]){
            int next_loc = next_island.first, limit = next_island.second;

            // 다리가 버틸 수 있는 하중(limit)이 타겟 무게 이상이면 건넘
            if (!visited[next_loc] && limit >= target_weight){
                visited[next_loc] = true;
                myqueue.push(next_loc);
            }
        }
    }

    return false;
}

void solve(){
    int left = 1, right = max_weight;
    int res = 0; // 최대 중량 기록

    while (left <= right){
        int mid = (left + right) / 2;

        if (BFS(mid)){
            // 갈 수 있다면 정답 기록 + 더 무겁게 시도
            res = mid;
            left = mid + 1;
        }
        else right = mid - 1; // 갈 수 없다면 무게 줄이기
    }

    cout << res;
}

int main(){
    fastio
    input();
    solve();
    return 0;
}
