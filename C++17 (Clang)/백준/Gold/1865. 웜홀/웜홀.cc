#include <bits/stdc++.h>
#define MAX 501
#define INF 25000001
using namespace std;

vector<pair<int, int>> graph[MAX];

int TC, N, M, W, S, E, T;

bool solve(){
    vector<int> dist(N + 1, INF);

    dist[1] = 0;

    for (int i = 1 ; i < N ; ++i){ 
        for (int u = 1 ; u <= N ; ++u){
            for (auto node : graph[u]){
                int v = node.first, w = node.second;
                if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
            }
        }
    }

    for (int u = 1 ; u <= N ; ++u){ 
        for (auto node : graph[u]){
            int v = node.first, w = node.second;
            if (dist[v] > dist[u] + w) return true;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> TC;

    while (TC--){
        cin >> N >> M >> W;

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