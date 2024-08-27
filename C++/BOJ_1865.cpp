#include <bits/stdc++.h>
#define MAX 501
#define distmax 25'000'001
#define INF INT_MAX

using namespace std;

int test_case, N, M, W, S, E, T;

vector<pair<int, int>> graph[MAX];

bool solve(){ // 벨만-포드 알고리즘
    vector<int> dist(N + 1, distmax);
    
    // 모든 노드를 출발점으로 하지 않아도 됨
    dist[1] = 0;

    for (int i = 1 ; i < N ; ++i){
        for (int u = 1 ; u <= N ; ++u){
            for (auto& node : graph[u]){
                int v = node.first, w = node.second;

                if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
            }
        }
    }

    // 음수 사이클 존재 여부 확인
    for (int u = 1 ; u <= N ; ++u){
        for (auto node : graph[u]){
            int v = node.first, w = node.second;

            if (dist[v] > dist[u] + w)
                return true;    
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> test_case;

    while (test_case--){

        cin >> N >> M >> W;

        // 테스트케이스마다 그래프 초기화 우선
        for (int i = 1 ; i <= N ; ++i) 
            graph[i].clear();
        

        for (int i = 0 ; i < M ; ++i){
            cin >> S >> E >> T;
            graph[S].push_back({E, T});
            graph[E].push_back({S, T});
        }

        for (int i = 0 ; i < W ; ++i){
            cin >> S >> E >> T;
            graph[S].push_back({E, -T});
        }

        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
