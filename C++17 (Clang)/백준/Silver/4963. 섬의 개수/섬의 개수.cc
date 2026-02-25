#include <iostream>
#include <queue>
#include <cstring>
#define MAX 51
#define endl '\n'
using namespace std;
int island[MAX][MAX];
bool visited[MAX][MAX];
int w, h;
struct Point{
    int x, y;
};
int D[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
void BFS(int x, int y){
    queue<Point> myqueue;
    myqueue.push({x, y});
    visited[x][y] = true;
    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        for (int i = 0; i < 8; ++i){
            int nx = curr.x + D[i][0];
            int ny = curr.y + D[i][1];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (!visited[nx][ny] && island[nx][ny] == 1){
                visited[nx][ny] = true;
                myqueue.push({nx, ny});
            }
        }
    }
}
int main(){
    while (true){
        int islandCnt = 0;
        memset(visited, false, sizeof(visited));
        memset(island, 0, sizeof(island));
        cin >> h >> w; 
        if (w == 0 && h == 0) break;
        for (int i = 0; i < w; ++i) 
            for (int j = 0; j < h; ++j)
                cin >> island[i][j];
        for (int i = 0; i < w; ++i){
            for (int j = 0; j < h; ++j){
                if (!visited[i][j] && island[i][j] == 1){
                    islandCnt += 1;
                    BFS(i, j);
                }
            }
        }
        cout << islandCnt << endl;
    }
    return 0;
}
