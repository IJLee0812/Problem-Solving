#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
struct Player{
    int x, cnt;
};
int N, M, Board[MAX];
bool visited[MAX];

void BFS(){
    queue<Player> myqueue;
    myqueue.push({1, 0});
    while(!myqueue.empty()){
        Player curr = myqueue.front();
        myqueue.pop();
        for (int i = 1 ; i <= 6 ; ++i){
            int nx = curr.x + i;
            if (nx == 100){
                cout << curr.cnt + 1;
                return;
            }
            if (nx < 100){
                while(Board[nx] != 0) nx = Board[nx]; // 사다리/뱀 업데이트
                if (!visited[nx]){
                    myqueue.push({nx, curr.cnt + 1});
                    visited[nx] = true;
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;
    int x, y, u, v;
    for (int i = 0 ; i < N ; ++i){
        cin >> x >> y;
        Board[x] = y;
    }
    for (int j = 0 ; j < M ; ++j){
        cin >> u >> v;
        Board[u] = v;
    }
    BFS();
    return 0;
}