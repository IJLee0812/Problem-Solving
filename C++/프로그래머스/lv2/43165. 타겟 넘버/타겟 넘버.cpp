#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    stack<pair<int, int>> s;
    s.push({0, 0});
    
    while (!s.empty()){
        pair<int, int> curr = s.top();
        s.pop();
        
        int currIdx = curr.first, currSum = curr.second;
        
        if (currIdx == numbers.size()){
            if (currSum == target)
                answer++;
            else continue; // 아무 처리 안 하고, 다음 state 검사.
        }

        else{
            s.push({currIdx + 1, currSum + numbers[currIdx]});
            s.push({currIdx + 1, currSum - numbers[currIdx]});
        }

    }

    return answer;
}