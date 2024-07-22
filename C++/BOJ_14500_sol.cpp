#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}, Map[501][501], visited[501][501], N, M, res = 0;

void solve(int x, int y, int cnt, int curScore){
    if (cnt == 4){ // 재귀 종료조건
        if (res < curScore) res = curScore;
        return;
    }

    for (int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 1 || ny < 1 || nx > N || ny > M || visited[nx][ny]) continue;

        visited[nx][ny] = 1;

        solve(nx, ny, cnt + 1, curScore + Map[nx][ny]);

        visited[nx][ny] = 0; // 백트래킹
    }

    if (x - 1 >= 1 && x + 1 <= N && y - 1 >= 1) // ㅓ
        res = max(res, Map[x - 1][y] + Map[x][y - 1] + Map[x][y] + Map[x + 1][y]);
    
    if (x - 1 >= 1 && x + 1 <= N && y + 1 <= M) // ㅏ
        res = max(res, Map[x - 1][y] + Map[x][y + 1] + Map[x][y] + Map[x + 1][y]);
    
    if (x + 1 <= N && y - 1 >= 1 && y + 1 <= M) // ㅗ
        res = max(res, Map[x][y] + Map[x + 1][y] + Map[x + 1][y - 1] + Map[x + 1][y + 1]);

    if (x + 1 <= N && y - 1 >= 1 && y + 1 <= M)
        res = max(res, Map[x][y - 1] + Map[x][y] + Map[x][y + 1] + Map[x + 1][y]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j <= M ; ++j)
            cin >> Map[i][j];
        
    for (int i = 1 ; i <= N ; ++i){
        for (int j = 1 ; j <= M ; ++j){
            visited[i][j] = 1;
            
            solve(i, j, 1, Map[i][j]);

            visited[i][j] = 0; // 백트래킹
        }
    }

    cout << res;
    return 0;
}
