#include <bits/stdc++.h>
#define MAX 1001
#define INF INT_MAX
using namespace std;

int N, M, X;
vector<pair<int, int>> graph[2][MAX];
bool visited[2][MAX];
int dist[2][MAX];

void solve(int idx){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, X}); // dist, vertex
    dist[idx][X] = 0;

    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if (visited[idx][u]) continue;
        visited[idx][u] = true;

        for (auto node : graph[idx][u]){
            int v = node.first, weight = node.second;
            if (dist[idx][v] > dist[idx][u] + weight){
                dist[idx][v] = dist[idx][u] + weight;
                pq.push({dist[idx][v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> X;

    int u, v, w;
    while (M--){
        cin >> u >> v >> w;
        graph[0][u].push_back({v, w});
        graph[1][v].push_back({u, w});
    }

    fill(dist[0], dist[0] + MAX, INF);
    fill(dist[1], dist[1] + MAX, INF);

    solve(0); solve(1);

    int res = 0;
    for (int i = 1 ; i <= N ; ++i)
        if (res < dist[0][i] + dist[1][i])
            res = dist[0][i] + dist[1][i];

    cout << res;
    return 0;
}