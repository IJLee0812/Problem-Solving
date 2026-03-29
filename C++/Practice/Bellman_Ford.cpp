/*
================================================================================
[벨만-포드(Bellman-Ford) 알고리즘 템플릿]

<테스트용 그래프 예시>
정점(V) = 6개, 간선(E) = 8개 (음수 가중치 포함, 음수 사이클은 없음)

   (1) --[5]--> (2) --[1]--> (4) --[-1]--> (6)
    |            |            ^             ^
   [4]         [-2]           |             |
    |            v            |             |
    +---------> (3) --[1]--> (5) --[2]------+
                 |            |
                 +---[ -3 ]---+
                 
실제 구성 간선 (u -> v : weight)
1 -> 2 :  5
1 -> 3 :  4
2 -> 3 : -2   (음수 간선: 1->2->3을 거치면 1->3보다 빨라짐!)
2 -> 4 :  1
3 -> 5 :  1
5 -> 4 : -3   (음수 간선: 5를 거쳐서 4로 가면 시간이 거꾸로 흐름!)
4 -> 6 : -1   (음수 간선)
5 -> 6 :  2

[예상되는 1번 정점부터의 최단 거리]
dist[1] = 0
dist[2] = 5
dist[3] = 3  (경로: 1 -> 2 -> 3 / 비용: 5 - 2 = 3)
dist[5] = 4  (경로: 1 -> 2 -> 3 -> 5 / 비용: 3 + 1 = 4)
dist[4] = 1  (경로: 1 -> 2 -> 3 -> 5 -> 4 / 비용: 4 - 3 = 1)
dist[6] = 0  (경로: 1 -> 2 -> 3 -> 5 -> 4 -> 6 / 비용: 1 - 1 = 0)
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e18 // 벨만포드에서는 넉넉하게 설정하여 오버플로우 방지
#define MAX 123
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N;
// dist에는 long long 사용해야 함에 유의(underflow 방지)
vector<pair<int, long long>> Graph[MAX]; 
long long dist[MAX];

void bellman_ford(int start){
    // 1. 최단거리 배열 초기화
    fill(dist, dist + N + 1, INF);
    dist[start] = 0;

    // 2. 'V - 1' 번 반복, 모든 간선 확인(최단거리 확정과정)
    for (int i = 1 ; i <= N - 1 ; ++i){
        // 모든 정점에 대해 확인(1 ~ N)
        for (int curr = 1 ; curr <= N ; ++curr){
            // [핵심] 아직 한 번도 도달하지 못한 정점이라면, 뻗어나가지 않음
            if (dist[curr] == INF) continue;

            for (const auto& edge : Graph[curr]){
                int next = edge.first;
                long long cost = edge.second;

                // 경로 갱신(다익스트라 동일)
                if (dist[next] > dist[curr] + cost) dist[next] = dist[curr] + cost;
            }
        }
    }

    // 3. 'V' 번째 반복으로, 음수 사이클 확인
    bool isNegativeCycle = false;
    for (int curr = 1 ; curr <= N ; ++curr){
        // [핵심] 아직 한 번도 도달하지 못한 정점이라면, 뻗어나가지 않음
        if (dist[curr] == INF) continue;

        for (const auto& edge : Graph[curr]){
            int next = edge.first;
            long long cost = edge.second;

            // [핵심] 'V - 1' 번 돌아서 모든 거리가 확정되었어야 하는데 갱신된다면 음수 사이클이 존재하는 것. 바로 break; 
            if (dist[next] > dist[curr] + cost){
                isNegativeCycle = true;
                break;
            }
        }
    }

    // 4. 결과 시각화 출력
    cout << "\n[벨만-포드 실행 결과]\n";
    if (isNegativeCycle) {
        cout << "🚨 치명적 경고: 그래프 내에 무한히 작아지는 '음수 사이클'이 존재합니다!\n";
    } else {
        cout << "✅ 탐색 성공! (음수 사이클 없음)\n";
        cout << "--------------------------------------------------\n";
        cout << "시작 정점(" << start << ")으로부터의 최단 거리:\n";
        for (int i = 1; i <= N; i++) {
            if (dist[i] == INF) cout << "정점 " << i << " : 도달 불가 (INF)\n";
            else cout << "정점 " << i << " : " << dist[i] << '\n';
        }
        cout << "--------------------------------------------------\n";
    }
}



int main(){
    fastio

    N = 6;

    Graph[1].push_back({2, 5});
    Graph[1].push_back({3, 4});
    Graph[2].push_back({3, -2});
    Graph[2].push_back({4, 1});
    Graph[3].push_back({5, 1});
    Graph[5].push_back({4, -10}); Graph[4].push_back({5, 2});
    Graph[4].push_back({6, -1});
    Graph[5].push_back({6, 2});

    cout << "==================================================\n";
    cout << "정점 " << N << "개짜리 테스트 그래프가 세팅되었습니다.\n";
    cout << "벨만-포드 알고리즘을 시작합니다...\n";
    cout << "==================================================\n";

    // 1번 정점을 시작점으로 하여 벨만-포드 실행
    bellman_ford(1);

    return 0;
}