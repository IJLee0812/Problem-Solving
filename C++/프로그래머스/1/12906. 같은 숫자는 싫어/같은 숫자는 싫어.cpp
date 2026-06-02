#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    deque<int> mydeque;
    
    for (auto n : arr) mydeque.push_back(n);
    
    int prev_num = mydeque.front();
    mydeque.pop_front();
    answer.push_back(prev_num);
    
    while (!mydeque.empty()){
        if (mydeque.front() == prev_num) mydeque.pop_front();
        else{
            answer.push_back(mydeque.front());
            prev_num = mydeque.front();
            mydeque.pop_front();
        }
    }
    
    return answer;
}