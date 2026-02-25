#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
struct Point{
    int x, y;
};
int M, N, Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<Point> myqueue;
void BFS(){
    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0];
            int ny = curr.y + D[i][1];
            if (nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
            if (Graph[nx][ny] == 0){
                Graph[nx][ny] = Graph[curr.x][curr.y] + 1;
                myqueue.push({nx, ny});
            }
        }
    }
}
int main(){
    cin >> M >> N;
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            cin >> Graph[i][j];
            if (Graph[i][j] == 1)
                myqueue.push({i, j});
        }
    }
    BFS();
    int day = 0;
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            if (Graph[i][j] == 0){
                cout << -1 << '\n';
                return 0;
            }
            if (Graph[i][j] > day) day = Graph[i][j];
        }
    }
    cout << day-1 << '\n';
    return 0;
}