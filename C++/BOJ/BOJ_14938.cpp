#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAX 102
#define INF 1234567890

using namespace std;

int n, m, r, a, b, l;

int items[MAX];
int item_count[MAX];

vector<pair<int, int>> Graph[MAX];
vector<int> dist;

/*
    n: 지역 개수
    m: 수색범위
    r: 길의 개수
    t: 각 구역 아이템의 수
    a, b: 양 끝에 존재하는 지역번호
    l: 길의 길이
*/

void input(){
    cin >> n >> m >> r;

    for (int i = 1 ; i <= n ; ++i) cin >> items[i];

    for (int i = 0 ; i < r ; ++i){
        cin >> a >> b >> l;
        Graph[a].push_back({b, l});
        Graph[b].push_back({a, l});
    }
}

void dijkstra(int start_node){
    dist.assign(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start_node}); // 거리, 점
    dist[start_node] = 0;

    while (!pq.empty()){
        int curr_dist = pq.top().first, curr_node = pq.top().second;

        pq.pop();

        if (dist[curr_node] < curr_dist) continue;
        
        for (auto edge : Graph[curr_node]){
            int next_node = edge.first, new_dist = edge.second;

            if (dist[next_node] > dist[curr_node] + new_dist){
                dist[next_node] = dist[curr_node] + new_dist;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    // 탐색 종료 후 거리 m 이하 아이템 합산
    int item_total = 0;
    for (int i = 1 ; i <= n ; ++i)
        if(dist[i] <= m) item_total += items[i];

    item_count[start_node] = item_total;
}

void solve(){
    for (int i = 1 ; i <= n ; ++i) dijkstra(i);

    int result = 0;

    for (int i = 1 ; i <= n ; ++i)
        if (result < item_count[i]) result = item_count[i];
    
    cout << result;
}

int main(){
    fastio
    input();
    solve();
    return 0;
}