#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10002
#define INF 1e9
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, D, dist[MAX];
vector<pair<int, int>> Graph[MAX];

void input(){
    cin >> N >> D;

    for (int i = 0 ; i < D ; ++i) Graph[i].push_back({i + 1, 1});

    int start, end, length; // 지름길 시작 위치, 도착 위치, 길이
    for (int i = 0 ; i < N ; ++i){
        cin >> start >> end >> length;

        // 필터링(불필요 저장 방지)
        if (end > D) continue;

        Graph[start].push_back({end, length});
    }
}

void solve(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    fill(dist, dist + D + 1, INF);
    dist[0] = 0;
    pq.push({dist[0], 0});

    while (!pq.empty()){
        int curr_dist = pq.top().first, curr_loc = pq.top().second;

        pq.pop();

        if (curr_dist > dist[curr_loc]) continue;

        for (const auto& node : Graph[curr_loc]){
            int next_loc = node.first, next_dist = node.second;

            if (dist[next_loc] > curr_dist + next_dist){
                dist[next_loc] = curr_dist + next_dist;
                pq.push({dist[next_loc], next_loc});
            }
        }
    }

    cout << dist[D];
}

int main(){
    fastio
    input();
    solve();
    return 0;
}