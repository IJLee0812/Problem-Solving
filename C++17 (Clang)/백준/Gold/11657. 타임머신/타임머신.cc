#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 502
#define INF 1e18

using namespace std;
using ll = long long;

vector<pair<int, int>> Graph[MAX];
ll times[MAX];

int N, M, A, B, C;

void input(){
    cin >> N >> M;
    for (int i = 0 ; i < M ; ++i){
        cin >> A >> B >> C;
        Graph[A].push_back({B, C});
    }
}

// 벨만포드
void solve(){
    // 1. times 초기화
    fill(times, times + N + 1, INF);
    times[1] = 0;

    // 3. N - 1 번 반복하여 최단시간 정보 갱신
    for (int i = 1 ; i <= N - 1 ; ++i){
        for (int curr = 1 ; curr <= N ; ++curr){
            if (times[curr] == INF) continue;

            for (const auto& edge : Graph[curr]){
                int next_node = edge.first; 
                ll next_time = edge.second;
                if (times[next_node] > times[curr] + next_time) times[next_node] = times[curr] + next_time;
            }
        }
    }

    // N 번째 반복에서, 음수 사이클 판별
    for (int curr = 1 ; curr <= N ; ++curr){
        if (times[curr] == INF) continue;

        for (const auto& edge : Graph[curr]){
            int next_node = edge.first;
            ll next_time = edge.second;
            if (times[next_node] > times[curr] + next_time){
                cout << "-1\n";
                return;
            }
        }
    }

    for (int i = 2 ; i <= N ; ++i){
        if (times[i] == INF) cout << "-1\n";
        else cout << times[i] << '\n';
    }
}

int main(){
    fastio
    input();
    solve();
    return 0;
}
