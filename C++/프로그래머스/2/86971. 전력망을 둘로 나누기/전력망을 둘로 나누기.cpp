#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int BFS(int exc_start, int exc_end, int n, const vector<vector<int>>& adj){
    queue<int> myqueue;
    myqueue.push(exc_start);
    int cnt = 1;
    vector<bool> visited(n + 1, false);
    visited[exc_start] = true;
    visited[exc_end] = true;
    
    while (!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        
        for (int next : adj[curr]){
            if (!visited[next]){
                visited[next] = true;
                myqueue.push(next);
                cnt++;
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 123;
    
    vector<vector<int>> adj(n + 1);
    
    for (const auto& wire : wires){
        int u = wire[0], v = wire[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (const auto& wire : wires){
        int exc_start = wire[0], exc_end = wire[1];
        
        int a = BFS(exc_start, exc_end, n, adj);
        int diff = abs(2 * a - n);
        
        answer = min(answer, diff);
    }
    
    return answer;
}