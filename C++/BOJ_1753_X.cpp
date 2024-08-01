#include <bits/stdc++.h>
#define MAX 20001
#define INF 99
using namespace std;

int graph[MAX][MAX];
int dist[MAX];
bool visited[MAX];
int V, E; 

void solve(int K){
    int iter = V;

    while (iter--){
        int minV = INF;
        visited[K] = true;
        for (int i = 1 ; i <= V ; ++i){
            if (graph[K][i] != 0)
                if (dist[K] + graph[K][i] < dist[i])
                    dist[i] = dist[K] + graph[K][i];
            
            if (!visited[dist[i]] && minV > dist[i]) 
                minV = dist[i];
        }
        K = minV;
    }

    for (int i = 1 ; i <= V ; ++i){
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V >> E; // V : 정점의 개수, E : 간선의 개수
    int K; cin >> K; // K : 시작 정점의 번호

    memset(dist, INF, sizeof(dist)); // 시작 정점 제외 전부 INF로 설정
    dist[K] = 0; // 시작 정점은 0으로 설정

    int u, v, w;
    for (int i = 0 ; i < E ; ++i){
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    solve(K);

    return 0;
}
