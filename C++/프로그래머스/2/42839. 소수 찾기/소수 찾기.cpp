#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> check;
int answer;

bool isPrime(int num){
    if (num < 2) return false;
    for (int i = 2 ; i * i <= num ; ++i)
        if (num % i == 0) return false;
    
    return true;
}

void dfs(string curr_str, const string& numbers, vector<bool>& visited){
    if (curr_str != "") check.insert(stoi(curr_str));
        
    for (int i = 0 ; i < numbers.length() ; ++i){
        if (!visited[i]){
            visited[i] = true;
            dfs(curr_str + numbers[i], numbers, visited);
            visited[i] = false;
        }  
    }
}

int solution(string numbers) {
    int n = numbers.length();
    
    vector<bool> visited(n + 1, false);
    
    dfs("", numbers, visited); // curr_str, numbers, visited 
    
    for (int num : check)
        if (isPrime(num)) answer++;
    
    return answer;
}