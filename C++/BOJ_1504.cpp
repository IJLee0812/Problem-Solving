#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 801
#define INF 200000000
using namespace std;

vector<pair<int, int>> graph[MAX];
vector<int> dist;
// vector<bool> visited; -> PQ 적용, 안써도 됨

int N, E, a, b, c, v1, v2;

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}


void dijkstra(int K){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist.assign(N + 1, INF);

    pq.push({0, K}); // {distance, vertex} 이고, distance를 기준으로 최소 힙 구조로 저장되어 오름차순 정렬되는 구조.
    dist[K] = 0; // 놓침주의

    while (!pq.empty()){
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (cost > dist[u]) continue; // 현재 꺼낸 거리가 이미 기록된 거리보다 크다면 스킵

        for (auto edge : graph[u]){
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}


int main(){
    fastio();

    cin >> N >> E;

    for (int i = 0 ; i < E ; ++i){
        cin >> a >> b >> c; // a <-> b: cost c
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> v1 >> v2; // 반드시 거쳐야 하는 정점 2개.

    dijkstra(1);
    int start_to_v1 = dist[v1], start_to_v2 = dist[v2];

    dijkstra(v1);
    int v1_to_N = dist[N], v1_to_v2 = dist[v2];

    dijkstra(v2);
    int v2_to_N = dist[N], v2_to_v1 = dist[v1];

    long long comp1 = start_to_v1 + v1_to_v2 + v2_to_N;
    long long comp2 = start_to_v2 + v2_to_v1 + v1_to_N;

    long long answer = min(comp1, comp2);

    if (answer >= INF) cout << -1 << endl;
    else cout << answer << endl;

    return 0;
}