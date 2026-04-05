#include<vector>
#include<bits/stdc++.h>
using namespace std;

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int BFS(vector<vector<int>> &maps){
    queue<pair<int, int>> q;
    int n = maps.size(); // 행 크기 = x
    int m = maps[0].size(); // 열 크기 = y
    
    vector<vector<int>> table(n, vector<int>(m, 0)); // 방문한 위치와 거리를 기록하는 테이블
    
    q.push({0, 0});
    table[0][0] = 1;
    
    while (!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.first + D[i][0];
            int ny = curr.second + D[i][1];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || maps[nx][ny] == 0 || table[nx][ny])
                continue;
            
            table[nx][ny] = table[curr.first][curr.second] + 1;
            q.push({nx, ny});
        }
    }
    
    return table[n - 1][m - 1] > 0 ? table[n - 1][m - 1] : -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = BFS(maps);
    return answer;
}