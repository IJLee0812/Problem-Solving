#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> adj(n + 1);    
    
    for (auto& e : edge){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    int max_dist = 0;
    
    vector<int> dist(n + 1, -1); // init -1 이면 하나갖다가 dist 랑 visited 범용으로 사용가능 
    queue<int> myqueue;
    myqueue.push(1);
    dist[1] = 0;
    
    while (!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        
        for (auto& next : adj[curr]){
            if (dist[next] == -1){
                dist[next] = dist[curr] + 1;
                myqueue.push(next);
            }
            
            if (dist[next] > max_dist) max_dist = dist[next];
        }
    }
    
    int answer = 0;
    
    for (int i = 1 ; i <= n ; ++i)
        if (dist[i] == max_dist) answer++;
    
    return answer;
}