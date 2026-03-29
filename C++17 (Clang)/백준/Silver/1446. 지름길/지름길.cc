#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10002
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int dist[MAX], N, D;

vector<pair<int, int>> shortcuts[MAX];

void input(){
    cin >> N >> D;

    int start, end, length;
    for (int i = 0 ; i < N ; ++i){
        cin >> start >> end >> length;

        // 필터링 로직(그냥 걸어가는 것 보다 길면 안 받음, e.g. 110 140 90)
        if (end > D || end - start <= length) continue;

        shortcuts[end].push_back({start, length});
    }
}

// DP
void solve(){
    dist[0] = 0;

    for (int i = 1 ; i <= D ; ++i){
        dist[i] = dist[i - 1] + 1;

        for (const auto& sc : shortcuts[i]){
            int start = sc.first, length = sc.second;
            dist[i] = min(dist[i], dist[start] + length);
        }
    }

    cout << dist[D];
}

int main(){
    fastio
    input();
    solve();
    return 0;
}