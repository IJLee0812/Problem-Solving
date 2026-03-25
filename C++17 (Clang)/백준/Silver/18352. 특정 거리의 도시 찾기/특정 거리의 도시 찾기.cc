#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 300002
#define INF 1e9
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, M, K, X, A, B;

vector<pair<int, int>> Graph[MAX];
int dist[MAX];

void input(){
    cin >> N >> M >> K >> X; // N: 도시 개수, M: 도로 개수, K: 거리 정보, X: 출발 도시 번호

    for (int i = 0 ; i < M ; ++i){
        cin >> A >> B;

        Graph[A].push_back({B, 1});
    }
}

void solve(){
    // 거리, 노드번호
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    fill(dist, dist + N + 1, INF);

    pq.push({0, X}); 
    dist[X] = 0;

    // dijkstra
    while (!pq.empty()){
        int u_dist = pq.top().first, u = pq.top().second;

        pq.pop();

        if (u_dist > dist[u]) continue;

        for (const auto &node : Graph[u]){  
            int v = node.first, v_dist = node.second;

            if (dist[v] > dist[u] + v_dist){
                dist[v] = dist[u] + v_dist;
                pq.push({dist[v], v});
            }
        }
    }

    bool flag = false;

    for (int i = 1 ; i <= N ; ++i){
        if (i != X && dist[i] == K){
            flag = true;
            cout << i << '\n';
        }
    }

    if (!flag) cout << "-1";
}

int main(){
    fastio
    input();
    solve();
    return 0;
}