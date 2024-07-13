#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
struct Player{
    int x, count;
};

int N, M, board[MAX];
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
                cout << curr.count + 1;
                return;
            }
            else if (nx < 100){
                while(board[nx] != 0)
                    nx = board[nx];
                if (!visited[nx]){
                    myqueue.push({nx, curr.count + 1});
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
        board[x] = y;
    }
    for (int j = 0 ; j < M ; ++j){
        cin >> u >> v;
        board[u] = v;
    }
    BFS();
    return 0;
}
