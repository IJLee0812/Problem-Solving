#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(int distance, const vector<int>& rocks, int n){
    int left = 1, right = distance, res = 0;
    
    while (left <= right){
        int mid = (left + right) / 2;
        int destroy_count = 0, prev_pos = 0;
        
        for (int rock : rocks){
            if (rock - prev_pos < mid) destroy_count++;
            else prev_pos = rock;
        }
        
        // 마지막 위치(prev_pos)에서, 도착 지점(distance) 까지의 거리
        if (distance - prev_pos < mid) destroy_count++;
        
        if (destroy_count > n) right = mid - 1;
        else{
            res = mid; // 정답 갱신해버리기
            left = mid + 1;
        }
    }
    
    return res;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    
    return binarySearch(distance, rocks, n);
}