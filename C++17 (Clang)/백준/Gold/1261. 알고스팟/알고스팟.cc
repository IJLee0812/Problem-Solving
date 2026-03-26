#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define INF 1e9
#define MAX 10002
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

vector<pair<int, int>> Graph[MAX];

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, M, N, V, start_node, end_node;
int dist[MAX];

void input(){
    cin >> M >> N; // M: 가로, N: 세로

    vector<string> board(N);
    for (int i = 0 ; i < N ; ++i) cin >> board[i];

    // coord compression (2-dim to 1-dim)
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= M ; ++c){
            int u = (r - 1) * M + c;

            for (int d = 0 ; d < 4 ; ++d){
                int nr = r + D[d][0], nc = c + D[d][1];

                if (nr >= 1 && nr <= N && nc >= 1 && nc <= M){
                    int v = (nr - 1) * M + nc; // 다음 칸
                    int weight = board[nr - 1][nc - 1] - '0';

                    Graph[u].push_back({v, weight});
                }
            }
        }
    }

    V = N * M;
    start_node = 1, end_node = V;
}

void solve(){
    fill(dist, dist + V + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start_node});
    dist[start_node] = 0;

    while (!pq.empty()){
        int u_cost = pq.top().first, u = pq.top().second;
        
        pq.pop();

        if (u_cost > dist[u]) continue;
        
        for (auto node : Graph[u]){
            int v = node.first, v_cost = node.second;

            if (dist[v] > u_cost + v_cost){
                dist[v] = u_cost + v_cost;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[end_node];
}

int main(){
    fastio
    input();
    solve();
    return 0;
}
