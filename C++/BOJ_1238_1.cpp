#include <bits/stdc++.h>
#define MAX 1001
#define INF INT_MAX
using namespace std;

int N, M, X;

vector<pair<int, int>> graph[MAX];
bool visited[MAX];
int dist[MAX];
int add[MAX];

int solve(int i){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, i}); // dist, vertex
    dist[i] = 0;
    // visited[i] = true;

    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto node : graph[u]){
            int v = node.first, weight = node.second;
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[X];
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> X; // X는 모이는 마을의 번호

    int u, v, w;
    while (M--){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for (int i = 1 ; i <= N ; ++i){
        if (i != X){
            fill(dist, dist + MAX, INF);        
            fill(visited, visited + MAX, false);
            add[i] = solve(i);
        }
    }

    fill(dist, dist + MAX, INF);
    fill(visited, visited + MAX, false);
    
    solve(X);

    int res = 0;
    for (int i = 1 ; i <= N ; ++i){
        dist[i] += add[i];
        if (res < dist[i]) res = dist[i];
    }

    cout << res;

    return 0;
}
