#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 10002
#define INF 1e18

using namespace std;
using ll = long long;

vector<pair<int, int>> Graph[MAX];

int N, M, A, B, C, start_loc, end_loc; // A -> B, Cost = C

ll weight[MAX];

void input(){
    cin >> N >> M;

    for (int i = 0 ; i < M ; ++i){
        cin >> A >> B >> C;

        Graph[A].push_back({B, C});
        Graph[B].push_back({A, C});
    }

    cin >> start_loc >> end_loc;
}

void solve(){
    priority_queue<pair<ll, int>> pq;
    pq.push({INF, start_loc});

    fill(weight, weight + N + 1, 0);
    weight[start_loc] = INF;

    while (!pq.empty()){
        ll curr_weight = pq.top().first;
        int curr_loc = pq.top().second;

        pq.pop();

        if (weight[curr_loc] > curr_weight) continue;

        for (const auto& island : Graph[curr_loc]){
            int new_loc = island.first;
            ll new_weight = island.second;

            int next_bottleneck  = min(curr_weight, new_weight);

            if (weight[new_loc] < next_bottleneck){
                weight[new_loc] = next_bottleneck;
                pq.push({weight[new_loc], new_loc});
            }
        }
    }

    cout << weight[end_loc];
}

int main(){
    fastio
    input();
    solve();
    return 0;
}