#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(const string& curr, const vector<vector<string>>& tickets, vector<bool> visited, vector<string>& path){
    if (path.size() == tickets.size() + 1) return true;
    
    for (int i = 0 ; i < tickets.size() ; ++i){
        if (!visited[i] && tickets[i][0] == curr){
            visited[i] = true;
            path.push_back(tickets[i][1]);
            
            if (DFS(tickets[i][1], tickets, visited, path)) return true;
            
            visited[i] = false;
            path.pop_back();
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    
    answer.push_back("ICN");
    
    DFS("ICN", tickets, visited, answer);
    return answer;
}