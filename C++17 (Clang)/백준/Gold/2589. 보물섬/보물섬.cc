// 큐에 투입시킴. BFS 마다 target_time를 두고, while 탈출하면 전역변수(정답) 거리랑 max(target_time, shortest_time) 로 갱신.

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 52

using namespace std;

int Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Point{
    int x, y, time;
};

bool visited[MAX][MAX];

int N, M; // N -> i, M -> j

queue<Point> land_points;

void input(){
    cin >> N >> M;

    string str;
    for (int i = 0 ; i < N ; ++i){
        cin >> str;

        // 육지 == L == 1, 바다 == W == 0
        for (int j = 0 ; j < M ; ++j){
            char ch = str[j];
            if (ch == 'L'){
                Graph[i][j] = 1;
                land_points.push({i, j});
            }
            else if (ch == 'W') Graph[i][j] = 0;
            else return;
        }
    }
}

int BFS(Point target){
    // visited 배열 초기화
    memset(visited, false, sizeof(visited));

    // 보물 찾는 데 소요되는 시간
    int target_max_time = 0;

    queue<Point> myqueue;
    myqueue.push({target.x, target.y, 0});
    visited[target.x][target.y] = true;

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

        target_max_time = max(target_max_time, curr.time);

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && Graph[nx][ny] == 1){
                visited[nx][ny] = true;
                myqueue.push({nx, ny, curr.time + 1});
            }
        }
    }

    return target_max_time;
}

void solve(){
    int shortest_time = 0;
    while (!land_points.empty()){
        Point target = land_points.front();
        land_points.pop();

        int x = target.x, y = target.y;

        if (x - 1 >= 0 && x + 1 < N && Graph[x - 1][y] == 1 && Graph[x + 1][y] == 1) continue;

        if (y - 1 >= 0 && y + 1 < M && Graph[x][y - 1] == 1 && Graph[x][y + 1] == 1) continue;

        shortest_time = max(shortest_time, BFS({target.x, target.y}));
    }

    cout << shortest_time;
}

int main(){
    fastio
    input();
    solve();
    return 0;
}