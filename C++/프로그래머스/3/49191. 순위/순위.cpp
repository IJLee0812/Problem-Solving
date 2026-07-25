#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(int target, vector<vector<int>> adj, vector<bool> visited){
    int a = 0;
    queue<int> myqueue;
    myqueue.push(target);
    visited[target] = true;
    
    while (!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        
        for (auto& next : adj[curr]){
            if (!visited[next]){
                myqueue.push(next);
                visited[next] = true;
                a++;
            }
        }
    }
    
    return a;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (int target = 1 ; target <= n ; ++target){
        vector<vector<int>> adj_f(n + 1); vector<bool> visited_f(n + 1, false);
        vector<vector<int>> adj_r(n + 1); vector<bool> visited_r(n + 1, false);    
        
        for (auto& res : results){
            int s = res[0], e = res[1];
            adj_f[s].push_back(e);
            adj_r[e].push_back(s);
        }
        
        int f = BFS(target, adj_f, visited_f);
        int r = BFS(target, adj_r, visited_r);
        
        if (f + r == (n - 1)) answer++;   
    }
    return answer;
}