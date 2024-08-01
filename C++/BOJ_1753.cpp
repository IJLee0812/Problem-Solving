#include <bits/stdc++.h>
#define MAX 20001
#define INF INT_MAX
using namespace std;

vector<pair<int, int>> graph[MAX]; // 인접 리스트를 활용하여 메모리를 효율적으로 관리한다.
int dist[MAX];
bool visited[MAX];
int V, E;

void solve(int K){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소 힙(dist 배열의 효율적 저장을 위함) 선언. pair<int, int>임에 유의한다.

    pq.push({0, K}); // {distance, vertex} 이고, distance를 기준으로 최소 힙 구조로 저장된다. 
    dist[K] = 0;

    while (!pq.empty()){
        int u = pq.top().second; // second임에 유의한다. front()가 아니며 -> top()으로 사용해야 한다.
        pq.pop();

        if (visited[u]) continue; // 방문했던(갱신 완료) 정점은 스킵한다.
        visited[u] = true; // 방문 처리를 해준다.

        for (auto edge : graph[u]){ // auto iterator 이용 시 편리하다. 순서에 유의한다.
            int v = edge.first; // vertex
            int weight = edge.second; // weight

            if (dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1 ; i <= V ; ++i){
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V >> E;
    int K; cin >> K;

    fill(dist, dist + MAX, INF);
    /*
        INF 초기화 문제
        > memset 함수는 바이트 단위로 초기화하기 때문에 INF 값을 올바르게 설정하지 못할 수 있다.
        따라서 배열 초기화 시 fill 함수를 사용하여 안전하게 초기화한다.
    */

    int u, v, w;
    for (int i = 0 ; i < E ; ++i){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    solve(K);

    return 0;
}
