#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    long long answer = 0, left = (long long) times[0], right = (long long) times[times.size() - 1] * n;
    
    while (left <= right){
        long long mid = (left + right) / 2, possible_n = 0;
        
        for (int i = 0 ; i < times.size() ; ++i) possible_n += mid / times[i];
        
        if (possible_n >= n){
            answer = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    
    return answer;
}