#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(int start_node, int n, vector<bool>& visited, const vector<vector<int>>& computers){
    queue<int> myqueue;
    
    myqueue.push(start_node);
    visited[start_node] = true;
    
    while (!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        
        for (int i = 0 ; i < n ; ++i){
            if (curr != i && computers[curr][i] && !visited[i]){
                visited[i] = true;
                myqueue.push(i);
            }
        }
    } 
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false); // 선언 + false 초기화

    int answer = 0;
    
    for (int i = 0 ; i < n ; ++i){
        if (!visited[i]){
            answer++;
            BFS(i, n, visited, computers);
        }
    }
    
    return answer;
}