#include <iostream>
#define MAX 20

using namespace std;

int N, Graph[MAX][MAX], answer = 0;

const int HORIZONTAL = 0, VERTICAL = 1, DIAGONAL = 2; // string 처리속도 저하 대응방안

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void input(){
    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> Graph[i][j];
}

bool can_move_diagonal(int target_x, int target_y){
    if (Graph[target_x][target_y]) return false;
    if (Graph[target_x - 1][target_y]) return false;
    if (Graph[target_x][target_y - 1]) return false;
    return true;
}

void DFS(int x, int y, int dir){
    // 종료조건
    if (x == N && y == N){
        answer++;
        return;
    }

    // 가로로 이동
    if (dir == HORIZONTAL || dir == DIAGONAL)
        if (y + 1 <= N && !Graph[x][y + 1]) DFS(x, y + 1, HORIZONTAL);
    

    // 세로로 이동
    if (dir == VERTICAL || dir == DIAGONAL){
        if (x + 1 <= N && !Graph[x + 1][y]) DFS(x + 1, y, VERTICAL);
    }

    // 대각선으로 이동
    if (x + 1 <= N && y + 1 <= N)
        if (can_move_diagonal(x + 1, y + 1)) DFS(x + 1, y + 1, DIAGONAL);
}

void solve(){
    DFS(1, 2, HORIZONTAL);
    cout << answer;
}

int main(){
    fastio();
    input();
    solve();
    return 0;
}