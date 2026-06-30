#include <string>
#include <vector>
using namespace std;

int answer = 0, _target;

void DFS(const vector<int>& numbers, int pos, int sum){
    int numbers_len = numbers.size();
    
    if (pos == (numbers_len)){
        if (sum == _target) answer += 1;
            
        return;
    }
 
    DFS(numbers, pos + 1, sum + numbers[pos]);
    DFS(numbers, pos + 1, sum - numbers[pos]);
}

int solution(vector<int> numbers, int target) {
    _target = target;
    answer = 0;
    DFS(numbers, 0, 0);
    
    return answer;
}