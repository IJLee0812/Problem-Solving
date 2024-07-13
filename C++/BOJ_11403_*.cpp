#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
int N, adj[MAX][MAX], sol[MAX][MAX];
void BFS(int startp){
    bool visited[MAX] = {false};
    queue<int> myqueue;
    myqueue.push(startp);
    while(!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        for (int newp = 0 ; newp < N ; ++newp){
            if (adj[curr][newp] == 0 || visited[newp]) continue;
            myqueue.push(newp);
            visited[newp] = 1;
        }
    }
    for (int i = 0 ; i < N ; ++i)
        sol[startp][i] = visited[i];
}
int main(){
    cin >> N;
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            cin >> adj[i][j];
        }
    }
    for (int i = 0 ; i < N ; ++i){
        BFS(i);
    }
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            cout << sol[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
