#include <vector>
#include <queue>
#include <algorithm>

struct Point{
    int x, y;
};

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

using namespace std;

void BFS(int& max_size_of_one_area, int m, int n, int i, int j, vector<vector<int>>& picture, vector<vector<bool>>& visited){
    queue<Point> myqueue;
    myqueue.push({i, j});
    visited[i][j] = true;
    int curr_size_of_area = 1, target_color = picture[i][j];
    
    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        
        for (int k = 0 ; k < 4 ; ++k){
            int nx = curr.x + D[k][0], ny = curr.y + D[k][1];
            
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && picture[nx][ny] == target_color){
                curr_size_of_area++;
                visited[nx][ny] = true;
                myqueue.push({nx, ny});
            }
        }
    }
    max_size_of_one_area = max(max_size_of_one_area, curr_size_of_area);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    for (int i = 0 ; i < m ; ++i){
        for (int j = 0 ; j < n ; ++j){
            if (!visited[i][j] && picture[i][j] > 0){ 
                BFS(max_size_of_one_area, m, n, i, j, picture, visited);
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}