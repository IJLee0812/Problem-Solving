#include <iostream>
#include <queue>
#define MAX 51
using namespace std;
struct Point{
    int x, y;
};

int Graph[MAX][MAX], M, N, K; 
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void BFS(int srcX, int srcY){
    queue<Point> myqueue;
    myqueue.push({srcX, srcY});
    Graph[srcX][srcY] = 0;
    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0];
            int ny = curr.y + D[i][1];
            if (nx < 0 || nx > M-1 || ny < 0 || ny > N-1) continue;
            if (Graph[nx][ny] == 0) continue;
            Graph[nx][ny] = 0;
            myqueue.push({nx, ny});
        }
    }
}

int main(){

    int T; cin >> T;
    int x, y;
    for (int i = 0 ; i < T ; ++i){
        cin >> M >> N >> K;
        for (int j = 0 ; j < K ; ++j){
            cin >> x >> y;
            Graph[x][y] = 1;
        }

        int worm = 0;
        for (int k = 0 ; k < M ; ++k){
            for (int l = 0 ; l < N ; ++l){
                if (Graph[k][l] == 1){
                    BFS(k, l);
                    worm++;
                }
            }
        }
        cout << worm << '\n';
    }

    return 0;
}