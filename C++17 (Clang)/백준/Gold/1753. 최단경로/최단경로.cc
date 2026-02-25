#include <bits/stdc++.h>
#define MAX 20001
#define INF INT_MAX
using namespace std;

vector<pair<int, int>> graph[MAX];
int dist[MAX];
bool visited[MAX];
int V, E;

void solve(int K) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, K});
    dist[K] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V >> E;
    int K; cin >> K;

    fill(dist, dist + MAX, INF);

    int u, v, w;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    solve(K);

    return 0;
}