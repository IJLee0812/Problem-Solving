#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int max_day = 0;
    
    for (int i = 0 ; i < progresses.size() ; ++i){
        int remain = 100 - progresses[i];
        int curr_day = (remain % speeds[i] == 0) ? (remain / speeds[i]) : (remain / speeds[i] + 1);
    
        // 첫 번째 배포이거나, 이전 배포 그룹보다 늦게 끝나는 기능일 경우
        if (answer.empty() || curr_day > max_day){
            answer.push_back(1);
            max_day = curr_day;
        }
        // 이전 배포 그룹과 함께 배포가능한 경우
        else answer.back()++; // 마지막 배포 그룹의 기능 개수 1 증가. back() -> ref 반환
    }
        
    return answer;
}