#include <bits/stdc++.h>
#define MAX 101
#define INF INT_MAX
using namespace std;

int graph[MAX][MAX], n, m;

void solve(){
    for (int k = 1 ; k <= n ; ++k)
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j)
                if (graph[i][k] != INF && graph[k][j] != INF) // 오버플로우 방지(중요) -> INT_MAX를 사용하고 해당 조건을 추가하는 것이 더 적절함. 1e9 같은 것들은 매우 큰 값이 경로 비용으로 사용될 때 부적절할 수 있음.
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    // graph 초기화
    for (int i = 1 ; i <= n ; ++i){
        for (int j = 1 ; j <= n ; ++j){
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    // 노드 정보 입력받기
    int a, b, c;
    while (m--){
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    // 플로이드 와샬 알고리즘
    solve();

    // 결과 출력
    for (int i = 1 ; i <= n ; ++i){
        for (int j = 1 ; j <= n ; ++j){
            if (graph[i][j] == INF) cout << "0 ";
            else cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}