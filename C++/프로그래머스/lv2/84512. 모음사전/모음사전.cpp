#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string target = "";
string vowels = "AEIOU";

void dfs(string word){
    cnt++;
    
    if (word == target){
        answer = cnt;
        return;
    }
    
    if (word.length() >= 5) return;
    
    for (int i = 0 ; i < 5 ; ++i) dfs(word + vowels[i]);
}

int solution(string word) {
    target = word;
    dfs("");
    return answer;
}