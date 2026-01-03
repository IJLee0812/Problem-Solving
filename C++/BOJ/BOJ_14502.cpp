#include <iostream>
#include <string.h>
#include <queue>
#define MAX 8
using namespace std;
int N, M, map[MAX][MAX], mapc[MAX][MAX], res, D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct Point{
    int x, y;
};
void BFS(){
    queue<Point> myqueue;
    int virusedMap[MAX][MAX];
    memcpy(virusedMap, mapc, sizeof(mapc));
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            if (virusedMap[i][j] == 2)
                myqueue.push({i, j});
    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0];
            int ny = curr.y + D[i][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (virusedMap[nx][ny] == 0){
                virusedMap[nx][ny] = 2;
                myqueue.push({nx, ny});
            }
        }
    }
    int cnt = 0;
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            if (virusedMap[i][j] == 0) cnt++;
    res = max(res, cnt);
}
void wall(int cnt){
    if (cnt == 3){
        BFS();
        return;
    }
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            if (mapc[i][j] == 0){
                mapc[i][j] = 1;
                wall(cnt + 1);
                mapc[i][j] = 0;
            }
        }
    }
}
int main(){
    cin >> N >> M;
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            cin >> map[i][j];
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            if (map[i][j] == 0){
                memcpy(mapc, map, sizeof(map));
                mapc[i][j] = 1;
                wall(1);
                mapc[i][j] = 0;
            }
        }
    }
    cout << res << '\n';
    return 0;
}