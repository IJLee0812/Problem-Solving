#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

struct Point{
    int x, y;
};
bool visited[MAX][MAX];
int N, M, Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<Point> myqueue;
void BFS(){
    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0];
            int ny = curr.y + D[i][1];
            if (nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
            if (visited[nx][ny]) continue;
            if (Graph[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            Graph[nx][ny] = Graph[curr.x][curr.y] + 1;
            myqueue.push({nx, ny});
            
        }
    }
}
int main(){
    cin >> N >> M;
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            cin >> Graph[i][j];
            if (Graph[i][j] == 2){
                myqueue.push({i, j});
                Graph[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    BFS();
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            if (!visited[i][j] && Graph[i][j] == 1) cout << "-1 ";
            else cout << Graph[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}