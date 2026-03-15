#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define MAX 52

using namespace std;

int R, C, T, curr_time = 1;
short A[MAX][MAX];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Point{
    int r, c;
};

struct Purifier{
    Point up, down;
};

struct Dust{
    int r, c, val; // val: 미세먼지 수치
};

Purifier purifier;

void input(){
    cin >> R >> C >> T;

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
}

void diffuse(){
    vector<Dust> dusts;

    // 1. 현재 맵에 존재하는 모든 미세먼지를 찾아 벡터에 저장
    for (int r = 1 ; r <= R ; ++r)
        for (int c = 1 ; c <= C ; ++c)
            if(A[r][c] > 0) dusts.push_back({r, c, A[r][c]});
    
    // 2. 벡터에 들어있는 먼지들만 꺼내서, 확산 진행
    for (auto d : dusts){
        int r = d.r, c = d.c;
        int div = d.val / 5;
        int cnt = 0;

        // 원본 값이 4 이하 == 나눌 양 0 == 확산 불필요(skip)
        if (div == 0) continue;

        for (int i = 0 ; i < 4 ; ++i){
            int nr = r + D[i][0], nc = c + D[i][1];

            if (A[nr][nc] != -1 && nr >= 1 && nr <= R && nc >= 1 && nc <= C){
                A[nr][nc] += div;
                cnt++;
            }
        }

        // (중요) 원래 위치에서는, 빠져나간 먼지만큼 빼준다. 이러면 tempA 만들 필요 없이 원본 A를 업데이트하면 됨
        A[r][c] -= (div * cnt);
    }
}


void purify(){
    int up_r = purifier.up.r, down_r = purifier.down.r;

    for (int r = up_r - 1 ; r > 1 ; --r) A[r][1] = A[r - 1][1];
    for (int c = 1 ; c < C ; ++c) A[1][c] = A[1][c + 1];
    for (int r = 1 ; r < up_r ; ++r) A[r][C] = A[r + 1][C];
    for (int c = C ; c > 2 ; --c) A[up_r][c] = A[up_r][c - 1];

    A[up_r][2] = 0; // 맑은 공기 처리

    for (int r = down_r + 1 ; r < R ; ++r) A[r][1] = A[r + 1][1];
    for (int c = 1 ; c < C ; ++c) A[R][c] = A[R][c + 1];
    for (int r = R ; r > down_r ; --r) A[r][C] = A[r - 1][C];
    for (int c = C ; c > 2 ; --c) A[down_r][c] = A[down_r][c - 1];

    A[down_r][2] = 0; // 맑은 공기 처리
}   

void simulation(){
    while (curr_time <= T){
        diffuse();
        purify();
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