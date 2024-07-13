#include <iostream>
#include <queue>
#define MAX 101
#define endl '\n'
using namespace std;
struct People{
    int people, dist;
};

int N, M, Graph[MAX][MAX], dist[MAX];;
queue<People> myqueue;

void BFS(int src){
    int totaldist = 0;
    bool visited[MAX] = { false };
    myqueue.push({src, 0});
    visited[src] = true;
    while(!myqueue.empty()){
        People curr = myqueue.front();
        myqueue.pop();
        totaldist += curr.dist;
        for (int i = 1 ; i <= N ; ++i){
            if (!visited[i] && Graph[curr.people][i]){
                visited[i] = true;
                myqueue.push({i, curr.dist + 1});
            }
        }
    }
    dist[src] = totaldist;
}

int main(){

    cin >> N >> M;
    int u, v;
    for (int i = 0 ; i < M ; ++i){
        cin >> u >> v;
        Graph[u][v] = Graph[v][u] = 1;
    }
    for (int i = 1 ; i <= N ; ++i){
        BFS(i);
    }
    int min = 5001, minind = 1;
    for (int i = 1 ; i <= N ; ++i){
        if (min > dist[i]){
            min = dist[i];
            minind = i;
        }
    }
    cout << minind << endl;
}