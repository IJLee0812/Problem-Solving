#include <iostream>
#include <cstring>
#include <cmath>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define MAX 52

using namespace std;

int R, C, T, curr_time = 1;
short A[MAX][MAX], tempA[MAX][MAX];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Point{
    int r, c;
};

struct Purifier{
    Point up, down;
};

Purifier purifier;

void debug_A(){
    cout << "\n\n";

    cout << "\ncurr_time: " << curr_time << "\n";

    for (int r = 1 ; r <= R ; ++r){
        for (int c = 1 ; c <= C ; ++c)
            cout << A[r][c] << ' ';
        
        cout << '\n';
    }
    cout << "\n\n";
}

void input(){
    cin >> R >> C >> T; // R: row, C: col, T: time

    bool isUp = false;
    for (int r = 1 ; r <= R ; ++r){
        for (int c = 1 ; c <= C ; ++c){
            cin >> A[r][c];

            if (A[r][c] == -1){
                if (!isUp){
                    isUp = true;
                    purifier.up.r = r, purifier.up.c = 1;
                }
                else{
                    purifier.down.r = r, purifier.down.c = 1;
                }
            }
        }
    }

    // cout << "purifier.up.r: " << purifier.up.r << ", purifier.up.c: " << purifier.up.c << '\n';
    // cout << "purifier.down.r: " << purifier.down.r << ", purifier.down.c: " << purifier.down.c << '\n';
    // debug_A();
}

void _diffuse(int r, int c){
    int cnt = 0;

    int origin = A[r][c], div = origin / 5;

    for (int i = 0 ; i < 4 ; ++i){
        int nr = r + D[i][0], nc = c + D[i][1];
        // 공기청정기 칸이 아니면서, 내부 칸
        if (A[nr][nc] != -1 && nr >= 1 && nr <= R && nc >= 1 && nc <= C){
            cnt++;
            tempA[nr][nc] += div;
        }
    }

    tempA[r][c] += origin - (div * cnt);
}

void diffuse(){
    memset(tempA, 0, sizeof(tempA));

    for (int r = 1 ; r <= R ; ++r)
        for (int c = 1 ; c <= C ; ++c)
            if (A[r][c] > 0) _diffuse(r, c); 
        
    for (int r = 1 ; r <= R ; ++r)
        for (int c = 1 ; c <= C ; ++c)
            if (A[r][c] != -1) A[r][c] = tempA[r][c];
}

void purify(){
    int up_r = purifier.up.r, down_r = purifier.down.r;

    // up = 반시계
    // 1. 왼쪽 세로줄 (아래로 당기기)
    for (int r = up_r - 1 ; r > 1 ; --r) A[r][1] = A[r - 1][1];
    // 2. 위쪽 가로줄 (왼쪽으로 당기기)
    for (int c = 1 ; c < C ; ++c) A[1][c] = A[1][c + 1];
    // 3. 오른쪽 세로줄 (위로 당기기)
    for (int r = 1 ; r < up_r ; ++r) A[r][C] = A[r + 1][C];
    // 4. 아래쪽 가로줄 (오른쪽으로 당기기)
    for (int c = C ; c > 2 ; --c) A[up_r][c] = A[up_r][c - 1];

    A[up_r][2] = 0; // 맑은 공기 처리

    // down = 시계
    // 1. 왼쪽 세로줄 (위로 당기기)
    for (int r = down_r + 1 ; r < R ; ++r) A[r][1] = A[r + 1][1];
    // 2. 아래쪽 가로줄 (왼쪽으로 당기기)
    for (int c = 1 ; c < C ; ++c) A[R][c] = A[R][c + 1];
    // 3. 오른쪽 세로줄 (아래로 당기기)
    for (int r = R ; r > down_r ; --r) A[r][C] = A[r - 1][C];
    // 4. 위쪽 가로줄 (오른쪽으로 당기기)
    for (int c = C ; c > 2 ; --c) A[down_r][c] = A[down_r][c - 1];

    A[down_r][2] = 0; // 맑은 공기 처리
}   

void simulation(){
    while (curr_time <= T){
        diffuse();
        // debug_A();
        purify();
        // debug_A();
        curr_time++;
    }
}

void output(){
    int sol = 0;
    for (int r = 1 ; r <= R ; ++r)
        for (int c = 1 ; c <= C ; ++c)
            if (A[r][c] > 0) sol += A[r][c];
    
    cout << sol;
}

int main(){
    fastio
    input();
    simulation();
    output();
    return 0;
}