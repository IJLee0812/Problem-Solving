#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 102

using namespace std;

int Graph[MAX][MAX];
bool visited[MAX][MAX];

struct Point{
    int y, x, dist;
};

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // init
    for (int i = 0 ; i < MAX ; ++i){
        for (int j = 0 ; j < MAX ; ++j){
            Graph[i][j] = 0;
            visited[i][j] = false;
        }
    }
    
    // rect 별 테두리 따기 (coord 2x)
    for (int i = 0 ; i < rectangle.size() ; ++i){
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for (int y = y1 ; y <= y2 ; ++y){
            for (int x = x1 ; x <= x2 ; ++x){
                if (y > y1 && y < y2 && x > x1 && x < x2) Graph[y][x] = 2;
                else{
                    if (Graph[y][x] != 2) Graph[y][x] = 1;
                }
            }
        }
    }
    
    // (시작점, 도착점) x 2
    int sx = characterX * 2;
    int sy = characterY * 2;
    int ex = itemX * 2;
    int ey = itemY * 2;
    
    // 테두리(1) BFS
    queue<Point> myqueue;
    myqueue.push({sy, sx, 0});
    visited[sy][sx] = true;
    
    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        
        int cx = curr.x, cy = curr.y, cd = curr.dist;
        
        // 거리 / 2 수행해야 정답. (좌표 x 2 했으므로)
        if (cx == ex && cy == ey) return cd / 2;
        
        for (int i = 0 ; i < 4 ; ++i){
            int ny = cy + D[i][0], nx = cx + D[i][1];
            
            if (ny >= 0 && ny < MAX && nx >= 0 && nx < MAX){
                if (Graph[ny][nx] == 1 && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    myqueue.push({ny, nx, cd + 1});
                }
            }
        }
    }
    
    return 0;
}