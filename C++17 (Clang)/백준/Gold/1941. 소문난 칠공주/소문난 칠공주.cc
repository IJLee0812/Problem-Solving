#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int Graph[6][6], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 1-based index, S: 1, Y: 0

struct Point{
    int x, y;
};

bool selected[25];

int cases = 0;

void input(){
    string str;
    for (int i = 0 ; i < 5 ; ++i){
        cin >> str;
        for (int j = 0 ; j < 5 ; ++j){
            if (str[j] == 'S') Graph[i][j] = 1;
            else Graph[i][j] = 0;
        }
    }
}

bool checkBFS(){
    queue<Point> myqueue;
    bool visited[5][5];
    memset(visited, false, sizeof(visited));

    for (int i = 0 ; i < 25 ; ++i){
        if (selected[i]){
            int startx = i / 5, starty = i % 5;
            myqueue.push({startx, starty});
            visited[startx][starty] = true;
            break;
        }
    }

    int connected_cnt = 1;

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visited[nx][ny]){
                int check_idx = nx * 5 + ny;
                if (selected[check_idx]){
                    visited[nx][ny] = true;
                    myqueue.push({nx, ny});
                    connected_cnt++;
                }
            }
        }
    }

    return (connected_cnt == 7);
}

void combination(int idx, int cnt, int S_cnt){
    // 종료조건
    if (cnt == 7){
        if (S_cnt >= 4)
            if (checkBFS()) cases++;
        return;
    }
        
    // 탐색: 'idx' 번 학생부터 24번 학생까지 순회
    for (int i = idx ; i < 25 ; ++i){
        if (!selected[i]){ // 백트래킹(조합)
            selected[i] = true; // 백트래킹(탐색시작)

            int nx = i / 5, ny = i % 5;

            // 다음 인덱스 탐색 + 총 cnt 갱신 + s_cnt 파라미터 갱신(S -> 1, Y -> 0 매핑했으므로 자동수행)
            combination(i + 1, cnt + 1, S_cnt + Graph[nx][ny]);

            selected[i] = false; // 백트래킹(원상복구)
        }
    }
}

void solve(){
    combination(0, 0, 0); // 25C7 칠공주 조합 구성, BFS()로 7명 연결성 검사 수행
    cout << cases;
}

int main(){
    input();
    solve();
    return 0;
}