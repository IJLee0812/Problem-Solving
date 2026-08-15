#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int curr_idx = 0, max_idx = progresses.size() - 1;

    while (curr_idx <= max_idx){
        int num_of_completed_progress = 0;
        
        for (int i = curr_idx ; i <= max_idx ; ++i){
            progresses[i] += speeds[i]; // 하루 개발.
        }
        
        
        for (int i = curr_idx ; i <= max_idx ; ++i){
            if (progresses[curr_idx] >= 100){
                curr_idx += 1;
                num_of_completed_progress += 1;
            }
        }
        
        if (num_of_completed_progress > 0)
            answer.push_back(num_of_completed_progress);
        
    }
    
    return answer;
}


/*
- 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발 가능.
- 뒤에 있는 기능은 앞에 있는 기능 배포 시 함께 배포되어야 함
- progresses 배열: 기능 순서(먼저 배포되어야 함) 대로 작업 진도(100 미만)가 적힌 int 배열
- speeds 배열: 각 작업의 개발 속도


- output: 각 배포마다 몇 개의 기능이 배포되는가?
*/
