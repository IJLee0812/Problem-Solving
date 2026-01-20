#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1002
#define INF 123456789

using namespace std;

int n, m, a, b, c, startc, endc; 

vector<pair<int, int>> Graph[MAX];
vector<int> dist;
vector<int> route;

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void input(){
    cin >> n >> m;

    for (int i = 0 ; i < m ; ++i){
        cin >> a >> b >> c;
        Graph[a].push_back({b, c});
    }

    cin >> startc >> endc;
}

void solve(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, startc});

    dist.resize(n + 1, INF);
    route.resize(n + 1, 0);

    dist[startc] = 0;

    while (!pq.empty()){
        int u_dist = pq.top().first, u = pq.top().second;

        pq.pop();

        if (dist[u] < u_dist) continue;

        for (auto node : Graph[u]){
            int v = node.first;
            int v_dist = node.second;

            if (dist[v] > dist[u] + v_dist){
                dist[v] = dist[u] + v_dist;

                pq.push({dist[v], v});
                
                route[v] = u; // 이전경로 로깅
            }
        }
    }

    // 최소 비용 출력
    cout << dist[endc] << '\n';

    // 경로 백트래킹
    vector<int> path;
    int curr = endc;

    while (curr != startc){
        path.push_back(curr);
        curr = route[curr];
    }

    path.push_back(startc);
    reverse(path.begin(), path.end());

    // 도시 개수 출력
    cout << path.size() << '\n';

    // 경로 출력
    for (auto node : path) cout << node << " ";
}

int main(){
    fastio();
    input();
    solve();
    return 0;
}