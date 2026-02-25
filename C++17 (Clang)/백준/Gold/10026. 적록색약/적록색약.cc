#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;
struct Point{
    int x, y;
};
int cnt1 = 0, cnt2 = 0, N, D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char Pic[MAX][MAX];
bool visited[MAX][MAX];
void BFS1(int srcX, int srcY){
    queue<Point> myqueue;
    myqueue.push({srcX, srcY});
    visited[srcX][srcY] = true;
    char srcCol = Pic[srcX][srcY];
    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0];
            int ny = curr.y + D[i][1];
            if (nx < 0 || nx > N-1 || ny < 0 || ny > N-1) continue;
            if (srcCol != Pic[nx][ny]) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            myqueue.push({nx, ny});
        }
    }
    cnt1++;
}   
void BFS2(int srcX, int srcY){
    queue<Point> myqueue;
    myqueue.push({srcX, srcY});
    visited[srcX][srcY] = true;
    char srcCol = Pic[srcX][srcY];
    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0];
            int ny = curr.y + D[i][1];
            if (nx < 0 || nx > N-1 || ny < 0 || ny > N-1) continue;
            if (srcCol == 'R' || srcCol == 'G')
                if (Pic[nx][ny] == 'B') continue;
            if (srcCol == 'B')
                if (Pic[nx][ny] == 'R' || Pic[nx][ny] == 'G') continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            myqueue.push({nx, ny});
        }
    }
    cnt2++;
}   
int main(){
    cin >> N;
    for (int i = 0 ; i < N ; ++i){
        string str;
        cin >> str;
        for (int j = 0 ; j < N ; ++j)
            Pic[i][j] = str[j];
    }
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            if (!visited[i][j]){
                BFS1(i, j);
            }
        }
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            if (!visited[i][j]){
                BFS2(i, j);
            }
        }
    }
    cout << cnt1 << ' ' << cnt2 << '\n';
    return 0;
}