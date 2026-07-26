#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20002   

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> Graph(n + 1);
    
    for (const auto& e : edge){
        Graph[e[0]].push_back(e[1]);
        Graph[e[1]].push_back(e[0]);
    }
    
    int max_dist = 0;
    
    vector<int> dist(n + 1, -1);
    
    queue<int> myqueue;
    myqueue.push(1);
    dist[1] = 0;
    
    while (!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        
        for (const auto& next : Graph[curr]){
            if (dist[next] == -1){ // 아직 방문X
                dist[next] = dist[curr] + 1;
                myqueue.push(next);
            }
            
            max_dist = max(max_dist, dist[next]);
        }
    }
    
    for (int i = 1 ; i <= n ; ++i)
        if (dist[i] == max_dist) answer++;
    
    return answer;
}