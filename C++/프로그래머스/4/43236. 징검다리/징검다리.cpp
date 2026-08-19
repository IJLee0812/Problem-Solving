#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int answer = 0;

void binarySearch(const vector<int>& rocks, int n, int left, int right){
    int _distance = right;
    while (left <= right){
        int mid = (left + right) / 2;
        int destroy_count = 0, prev_pos = 0;
        
        for (int i = 0 ; i < rocks.size() ; ++i){
            int dist = rocks[i] - prev_pos;
            
            if (dist < mid) destroy_count++;
            else prev_pos = rocks[i];
        }
        
        // 마지막 위치(prev_pos)에서, 도착 지점(distance) 까지의 거리도 체크해야 됨.
        if (_distance - prev_pos < mid) destroy_count++;
        
        
        if (destroy_count > n) right = mid - 1;
        else{
            answer = max(answer, mid);
            left = mid + 1;
        }
    }
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    binarySearch(rocks, n, 0, distance); // rocks, n, init {left, right}
    return answer;
}