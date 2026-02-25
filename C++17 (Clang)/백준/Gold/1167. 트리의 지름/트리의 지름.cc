#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int V;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];

pair<int, int> solve(int k, int cnt){
    pair<int, int> res = {k, cnt};
    visited[k] = true;

    for (auto node : graph[k]){
        int next = node.first, weight = node.second;

        if (!visited[next]){
            pair<int, int> temp = solve(next, cnt + weight);
            if (temp.second > res.second) res = temp;
        }
    }

    return res;
}

int main(){
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