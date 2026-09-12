#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, T;
int answer = 0;
vector<vector<vector<int>>> signals;
vector<vector<bool>> visited;
bool checked[100][100][4][101];

// int sign_map[13][3][2] = {
//     {{0, 0}, {0, 0}, {0, 0}}, // temp
//     {{-1, 0}, {0, 1}, {1, 0}}, // 신호 1(3방향)
//     {{0, -1}, {-1, 0}, {0, 1}},
//     {{-1, 0}, {0, -1}, {0, 1}},
//     {{0, -1}, {1, 0}, {0, 1}}, // 신호 4(3방향)
//     {{-1, 0}, {0, 1}, {0, 0}}, // 신호 5(2방향. 하나는 (0, 0) 으로 채우기)
//     {{0, -1}, {-1, 0}, {0, 0}},
//     {{0, -1}, {1, 0}, {0, 0}},
//     {{1, 0}, {0, 1}, {0, 0}},
//     {{0, 1}, {1, 0}, {0, 0}},
//     {{-1, 0}, {0, 1}, {0, 0}},
//     {{-1, 0}, {0, -1}, {0, 0}},
//     {{0, -1}, {1, 0}, {0, 0}}, // 신호 12
// };

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 0=북, 1=남, 2=서, 3=동

// TURN[0] = 좌회전, 1 = 직진, 2 = 우회전
int TURN[3][4] = {
    {2, 3, 1, 0}, 
    {0, 1, 2, 3},
    {3, 2, 0, 1}
};

int sign_map[13][4] = {
    {-1, 0, 0, 0},  // index 0: temp
    { 3, 1, 1, 1},  // 신호 1  : 동쪽으로 진행 중인 차, 좌직우
    { 0, 1, 1, 1},  // 신호 2  : 북
    { 2, 1, 1, 1},  // 신호 3  : 서
    { 1, 1, 1, 1},  // 신호 4  : 남
    { 3, 1, 1, 0},  // 신호 5  : 동, 좌직
    { 0, 1, 1, 0},  // 신호 6  : 북, 좌직
    { 2, 1, 1, 0},  // 신호 7  : 서, 좌직
    { 1, 1, 1, 0},  // 신호 8  : 남, 좌직
    { 3, 0, 1, 1},  // 신호 9  : 동, 직우
    { 0, 0, 1, 1},  // 신호 10 : 북, 직우
    { 2, 0, 1, 1},  // 신호 11 : 서, 직우
    { 1, 0, 1, 1},  // 신호 12 : 남, 직우
};

void DFS(int r, int c, int dir, int time){
    if (time == T) return;

    int curr_signal = signals[r][c][time % 4];
    if (sign_map[curr_signal][0] != dir) return; // 4방향 중 3방향 거르기

    for (int m = 0 ; m < 3 ; ++m){ // m = 0: 좌, 1: 직, 2: 우
        if (!sign_map[curr_signal][m + 1]) continue; // 정의되지 않은 maneuver cut
    
        int ndir = TURN[m][dir];
        int nr = r + D[ndir][0], nc = c + D[ndir][1];

        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if (checked[nr][nc][ndir][time + 1]) continue;

        checked[nr][nc][ndir][time + 1] = true;
        visited[nr][nc] = true;
        DFS(nr, nc, ndir, time + 1);
    }   
}

int main(){
    fastio
    cin >> N >> T;

    signals.resize(N, vector<vector<int>>(N, vector<int>(4)));
    visited.assign(N, vector<bool>(N, false));
    visited[0][0] = true;

    for (int r = 0; r < N; r++) 
        for (int c = 0; c < N; c++) 
            for (int k = 0; k < 4; k++) 
                cin >> signals[r][c][k];

    DFS(0, 0, 0, 0); // init x, y, dir, time

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            if (visited[i][j]) answer++;

    cout << answer;
    return 0;
}