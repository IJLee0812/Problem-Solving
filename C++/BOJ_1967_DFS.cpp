#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int n;
bool visited[MAX];
vector<pair<int, int>> graph[MAX];

int res = 0, end_point; // 지름에 해당하는 끝점

void solve(int point, int length){
    if (visited[point]) return; // DFS 종료조건

    visited[point] = true; // 방문 표시(누락 주의)

    if (res < length){
        res = length;
        end_point = point;
    }

    for (int i = 0 ; i < graph[point].size() ; ++i){ // point와 인접한 정점 모두 탐색
        solve(graph[point][i].first, length + graph[point][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    int u, v, w;

    for (int i = 0 ; i < n - 1 ; ++i){ // i == (n - 2) 까지임. 문제 똑바로 읽을 것.
        cin >> u >> v >> w; // w : weight

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // 루트 노드 기준으로 가장 멀리 있는 정점(end_point) 구하기
    solve(1, 0); // 1 : root node

    res = 0; // 초기화 필요
    memset(visited, false, sizeof(visited));
    solve(end_point, 0);
    
    cout << res; // 길이 정보만 필요함
    return 0;
}