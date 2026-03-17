#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 102

using namespace std;

int M, N, K, cnt = 0;
int Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[MAX][MAX];

struct coord{
    int x, y;
};

struct Point{
    coord start, end;
};

vector<Point> points;
vector<int> areas;

void input(){
    cin >> M >> N >> K; // M: 세로(Y), N: 가로(X)

    int sx, sy, ex, ey;

    for (int i = 0 ; i < K ; ++i){
        cin >> sx >> sy >> ex >> ey;
        points.push_back({{sx, sy}, {ex, ey}});
    }
}

void _fill(Point point){
    for (int i = point.start.x ; i < point.end.x ; ++i)
        for (int j = point.start.y ; j < point.end.y ; ++j)
            Graph[i][j] = 1;
}

void BFS(int i, int j){
    queue<coord> myqueue;
    myqueue.push({i, j});
    visited[i][j] = true;

    int area_cnt = 1;

    while (!myqueue.empty()){
        coord curr = myqueue.front();
        myqueue.pop();

        for (int k = 0 ; k < 4 ; ++k){ 
            int nx = curr.x + D[k][0], ny = curr.y + D[k][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || Graph[nx][ny]) continue;
            
            visited[nx][ny] = true;
            myqueue.push({nx, ny});
            area_cnt++;
        }
    }

    cnt++;
    areas.push_back(area_cnt);
}

void solve(){
    for (const auto& point : points) _fill(point);

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            if (!Graph[i][j] && !visited[i][j]) BFS(i, j);
 
    cout << cnt << '\n';

    sort(areas.begin(), areas.end());
    for (auto area : areas) cout << area << ' ';
}

int main(){
    fastio
    input();
    solve();
    return 0;
}