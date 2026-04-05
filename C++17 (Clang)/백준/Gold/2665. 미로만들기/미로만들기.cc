#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 52
#define INF 1e9

using namespace std;

int Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dist[MAX][MAX], N;

struct Point{
    int x, y;
    const bool operator<(const Point& p) const{
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

void input(){
    cin >> N;
    string str;
    for (int i = 0 ; i < N ; ++i){
        cin >> str;
        for (int j = 0 ; j < N ; ++j) Graph[i][j] = str[j] - '0';
    }
}

void solve(){
    priority_queue<pair<int, Point>, vector<pair<int, Point>>, greater<pair<int, Point>>> pq;

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            dist[i][j] = INF;

    dist[0][0] = 0;
    pq.push({0, {0, 0}}); // dist, Point;

    while (!pq.empty()){
        int curr_dist = pq.top().first;
        Point curr = pq.top().second;

        // 주의
        pq.pop();

        // opt
        if (curr_dist > dist[curr.x][curr.y]) continue;

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N){
                if (dist[nx][ny] > dist[curr.x][curr.y] + !Graph[nx][ny]){
                    dist[nx][ny] = dist[curr.x][curr.y] + !Graph[nx][ny];
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }

    cout << dist[N - 1][N - 1];
}

int main(){
    fastio 
    input();
    solve();
    return 0;
}