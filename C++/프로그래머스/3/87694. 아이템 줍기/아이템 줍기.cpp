#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 102

using namespace std;

struct Point{
    int x, y, dist;
};

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int Graph[MAX][MAX];
bool visited[MAX][MAX]; // for 1-BFS

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    memset(Graph, 0, sizeof(Graph));
    memset(visited, false, sizeof(visited));
    
    // 1. Graph 안에 좌표 x 2, 사각형 테두리 모델링
    
    for (int i = 0 ; i < rectangle.size() ; ++i){
        int sx = rectangle[i][0] * 2;
        int sy = rectangle[i][1] * 2;
        int ex = rectangle[i][2] * 2;
        int ey = rectangle[i][3] * 2;
        
        for (int x = sx ; x <= ex ; ++x){
            for (int y = sy ; y <= ey ; ++y){
                if (x > sx && x < ex && y > sy && y < ey) Graph[x][y] = 2;
                else if (Graph[x][y] != 2) Graph[x][y] = 1;
                
            }
        }
    }
    
    // 2. 1-BFS
    queue<Point> myqueue;
    int sx = characterX * 2, sy = characterY * 2;
    int tx = itemX * 2, ty = itemY * 2;
    myqueue.push({sx, sy, 0});
    visited[sx][sy] = true;
    
    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        
        if (curr.x == tx && curr.y == ty){
            answer = curr.dist / 2;
            break;
        }
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];
            if (Graph[nx][ny] == 1 && !visited[nx][ny]){
                visited[nx][ny] = true;
                myqueue.push({nx, ny, curr.dist + 1});
            }
        }
        
    }
    
    return answer;
}