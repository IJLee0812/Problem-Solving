#include <algorithm>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int BFS(int start, int cut_node, int n, const vector<vector<int>>& adj){
    vector<bool> visited(n + 1, false);
    int count = 1; // start node 포함 = 1
    queue<int> myqueue;
    myqueue.push(start);
    visited[start] = true; 
    visited[cut_node] = true; // 끊기 = visited true 표시하기와 동치
    
    while (!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        
        for (int next : adj[curr]){
            if (!visited[next]){
                visited[next] = true;
                myqueue.push(next);
                count++;
            }
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 123;
    vector<vector<int>> adj(n + 1);
    for (const auto& wire : wires){
        int u = wire[0], v = wire[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (const auto& wire : wires){ // "wire: 끊을 노드"
        int u = wire[0], v = wire[1];
        int cnt = BFS(u, v, n, adj);
        
        int diff = abs(2 * cnt - n);
        
        answer = min(answer, diff);
    }
    
    return answer;
}