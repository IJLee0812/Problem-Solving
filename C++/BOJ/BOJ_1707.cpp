#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 20002

using namespace std;

int K, V, E, u, v;

vector<int> Graph[MAX];
int color[MAX];

void init(){
    for (int i = 1 ; i <= V ; ++i){
        Graph[i].clear(); // 아예 비워줄 땐 resize 말고 clear 사용
        color[i] = 0;
    }
}

bool check(int curr){ 
    for (int next : Graph[curr]){
        if (!color[next]){
            color[next] = 3 - color[curr];

            if (!check(next)) return false;
        }
        else if (color[curr] == color[next]) return false;
    }

    return true;
}

void solve(){
    cin >> V >> E;

    init();

    for (int i = 0 ; i < E ; ++i){
        cin >> u >> v;

        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    bool is_bipartite = true;

    for (int i = 1 ; i <= V ; ++i){
        if (!color[i]){
            color[i] = 1;

            if (!check(i)){
            is_bipartite = false;
            break;
            }
        }
    }

    if (is_bipartite) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    fastio

    cin >> K;
    while (K--) solve();

    return 0;
}