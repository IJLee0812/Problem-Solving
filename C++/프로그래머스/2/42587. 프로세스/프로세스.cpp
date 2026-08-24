#include <queue>
#include <vector>

using namespace std;

struct Process{
    int priority, location;
};

int solution(vector<int> priorities, int location){
    int answer = 0;

    // 1. 일반 큐(시뮬레이션)
    queue<Process> myqueue;
    // 2. 우선순위 큐(남은 프로세스 중 최고 우선순위 추적)
    priority_queue<int> pq;

    for (int i = 0 ; i < priorities.size() ; ++i){
        myqueue.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    while (!myqueue.empty()){
        Process curr = myqueue.front();
        myqueue.pop();

        // 내 우선순위가 현재 대기열의 최고 우선순위와 같다면 (프로세스 실행 트리거)
        if (curr.priority == pq.top()){
            answer++;
            pq.pop();

            // 방금 실행한 것이 찾던 프로세스라면 종료
            if (curr.location == location) break;
        }
        else myqueue.push(curr);
    }

    return answer;
}