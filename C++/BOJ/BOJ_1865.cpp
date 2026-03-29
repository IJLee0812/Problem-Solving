#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 501
#define INF 1e18
using namespace std;

vector<pair<int, int>> Graph[MAX];

int TC, N, M, W, S, E, T;

bool solve(){
    vector<long long> dist(N + 1, INF); 

    dist[1] = 0;

    for (int i = 1 ; i < N ; ++i){ 
        for (int u = 1 ; u <= N ; ++u){
            for (auto node : Graph[u]){
                int v = node.first, w = node.second;
                if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
            }
        }
    }

    for (int u = 1 ; u <= N ; ++u){ 
        for (auto node : Graph[u]){
            int v = node.first, w = node.second;
            if (dist[v] > dist[u] + w) return true;
        }
    }

    return false;
}

int main(){
    fastio
    cin >> TC;

    while (TC--){
        cin >> N >> M >> W;

        for (int i = 1 ; i <= N ; ++i) Graph[i].clear();

        for (int i = 0 ; i < M ; ++i){
            cin >> S >> E >> T;
            Graph[S].push_back({E, T});
            Graph[E].push_back({S, T});
        }

        for (int i = 0 ; i < W ; ++i){
            cin >> S >> E >> T;
            Graph[S].push_back({E, -T});
        }

        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}