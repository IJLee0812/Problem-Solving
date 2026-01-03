#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

vector<pair<int, int>> graph[MAX];
int n;

pair<int, int> solve(int point){
    queue<int> q;
    int dist[MAX];
    bool visited[MAX];

    fill(visited, visited + MAX, false);

    q.push(point);
    visited[point] = true;
    dist[point] = 0;
    fill(dist, dist + MAX, 0);

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for (auto node : graph[curr]){
            if (!visited[node.first]){
                q.push(node.first);
                visited[node.first] = true;
                dist[node.first] = dist[curr] + node.second;
            }
        }
    }

    int maxv = 0, idx = -1;
    for (int i = 1 ; i <= n ; ++i){
        if (maxv < dist[i]){
            maxv = dist[i];
            idx = i;
        }
    }

    return make_pair(maxv, idx);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    if (n == 1){
        cout << '0';
        return 0;
    }

    int u, v, w;
    for (int i = 0 ; i < n - 1 ; ++i){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int endpoint = solve(1).second; // 1 : root node

    cout << solve(endpoint).first;
    return 0;
}