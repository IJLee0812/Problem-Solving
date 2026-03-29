#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1e9
#define MAX 126
using namespace std;

int Graph[MAX][MAX], dist[MAX][MAX], N, problem_cnt = 0, D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// bool visited[MAX][MAX];

// struct Point{
//     int x, y;
// };

void init(){
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            cin >> Graph[i][j];
            dist[i][j] = INF;
            // visited[i][j] = false;
        }
    }
}

void solve(){
    init();

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({Graph[0][0], {0, 0}});
    dist[0][0] = Graph[0][0];

    while (!pq.empty()){
        int curr_cost = pq.top().first;
        int cx = pq.top().second.first, cy = pq.top().second.second;
        
        pq.pop();

        for (int i = 0 ; i < 4; ++i){
            int nx = cx + D[i][0], ny = cy + D[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N){
                int next_cost = curr_cost + Graph[nx][ny];

                if (dist[nx][ny] > next_cost){
                    dist[nx][ny] = next_cost;
                    pq.push({next_cost, {nx, ny}}); // '갱신된 누적 비용' 을 pq에 삽입
                }
            }
        }
    }

    cout << "Problem " << problem_cnt << ": " << dist[N - 1][N - 1] << '\n';
}

int main(){
    fastio

    while (true){
        cin >> N;
        if (N == 0) return 0; // 종료조건
        
        problem_cnt++;
        solve();
    }

    return 0;
}