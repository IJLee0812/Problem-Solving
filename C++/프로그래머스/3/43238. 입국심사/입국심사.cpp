#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long answer = 0;

void binarySearch(int n, const vector<int>& times, long long left, long long right){
    // 재귀 종료조건
    if (left > right) return;
    
    long long mid = (left + right) / 2, possible_n = 0;
    for (int i = 0 ; i < times.size() ; ++i) possible_n += mid / times[i];
    
    if (possible_n >= n){
        answer = mid;
        binarySearch(n, times, left, mid - 1);
    }
    else binarySearch(n, times, mid + 1, right);
}

long long solution(int n, vector<int> times) {
    long long left = 1, right;
    sort(times.begin(), times.end());
    right = (long long) times[times.size() - 1] * n;
    
    binarySearch(n, times, left, right);
    
    return answer;
}