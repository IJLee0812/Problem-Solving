#include <string>
#include <vector>
#include <queue>

using namespace std;

void BFS(int target, int n, vector<bool> &visited, const vector<vector<int>> &computers){
    queue<int> myqueue;
    
    visited[target] = true;
    myqueue.push(target);
    
    while (!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        
        for (int i = 0 ; i < n ; ++i){
            if (!visited[i] && i != target && computers[curr][i]){
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    for (int i = 0 ; i < n ; ++i){
        if (!visited[i]){
            answer++;
            BFS(i, n, visited, computers);
        }
    }
    
    return answer;
}