#include <iostream>
#include <queue>
#include <string>
#define MAX 601
#define endl '\n'
using namespace std;
struct Point{
    int x, y;
};
int res = 0, N, M, D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char C[MAX][MAX];
queue<Point> myqueue;
bool visited[MAX][MAX];
void BFS(){
    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0];
            int ny = curr.y + D[i][1];
            if (nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
            if (visited[nx][ny]) continue;
            if (C[nx][ny] == 'X') continue;
            myqueue.push({nx, ny});
            visited[nx][ny] = true;
            if (C[nx][ny] == 'P') res++;
        }
    }
}
int main(){
    cin >> N >> M;
    for (int i = 0 ; i < N ; ++i){
        string str; cin >> str;
        for (int j = 0 ; j < str.length() ; ++j){
            C[i][j] = str[j];
            if (C[i][j] == 'I'){ 
                myqueue.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    BFS();
    if (res == 0) cout << "TT" << endl;
    else cout << res << endl;
    return 0;
}