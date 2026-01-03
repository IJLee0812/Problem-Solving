#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int V;
vector<pair<int, int>> graph[MAX]; // graph[start].push_back({end, weight}; // start : 출발 정점, end : 도착 정점, weight : 거리(가중치)
bool visited[MAX];

pair<int, int> solve(int k, int cnt){ // {정점 번호, 출발 정점에서 해당 정점까지의 누적 거리}
    pair<int, int> res = {k, cnt}; // 정보 저장
    visited[k] = true;

    for (auto node : graph[k]){
        int next = node.first, weight = node.second;
        if (!visited[next]){ // 방문하지 않은 다음 깊이의 정점
            pair<int, int> temp = solve(next, cnt + weight); 
            if (temp.second > res.second) res = temp; // 누적 거리 업데이트
        }
    }

    return res; // 재귀 호출 흐름 생각해보기(맨 끝 정점에서 res = temp 업데이트된 후, 거슬러 올라가도 더 이상 업데이트 되지 않음)
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V;

    int start, end, weight;
    while (V--){
        cin >> start;

        while (true){
            cin >> end;
            if (end == -1) break;
            cin >> weight;

            graph[start].push_back({end, weight});
        }
    }

    int ep = solve(1, 0).first;
    
    fill(visited, visited + MAX, false);
    cout << solve(ep, 0).second;

    return 0;
}
