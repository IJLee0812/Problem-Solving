#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
struct Point{
    int row, col, dist;
};
int N, M, Maze[MAX][MAX];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int BFS(int srcRow, int srcCol, int dstRow, int dstCol){
    bool visited[MAX][MAX] = { false };
    queue<Point> myqueue;
    visited[srcRow][srcCol] = true;
    myqueue.push({srcRow, srcCol, 1});
    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        if (curr.row == dstRow && curr.col == dstCol) return curr.dist;
        for (int i = 0 ; i < 4 ; ++i){
            int nr = curr.row + D[i][0];
            int nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
            if (visited[nr][nc]) continue;
            if (Maze[nr][nc] == 0) continue;
            visited[nr][nc] = true;
            myqueue.push({nr, nc, curr.dist+1});
        }
    }
    return -1;
}
int main(){
    cin >> N >> M;
    for (int i = 0 ; i < N ; ++i){
        string row; cin >> row;
        for (int j = 0 ; j < M ; ++j){
            Maze[i][j] = row[j] - '0';
        }
    }
    cout << BFS(0, 0, N-1, M-1);
    return 0;
}