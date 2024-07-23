#include <bits/stdc++.h>
using namespace std;

int Map[501][501], visited[501][501], res = 0, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, N, M;

void DFS(int x, int y, int cnt, int sum){
    if (cnt == 4){ // 재귀 종료조건
        if (res < sum) res = sum;
        return; // 재귀 종료
    }

    for (int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && !visited[nx][ny]){
            visited[nx][ny] = 1;
            DFS(nx, ny, cnt + 1, sum + Map[nx][ny]);
            visited[nx][ny] = 0; // Backtracking
        }
    }

    // ㅓ
    if (x - 1 >= 1 && x + 1 <= N && y - 1 >= 1)
        res = max(res, Map[x][y] + Map[x - 1][y] + Map[x + 1][y] + Map[x][y - 1]);

    // ㅏ
    if (x - 1 >= 1 && x + 1 <= N && y + 1 <= M)
        res = max(res, Map[x][y] + Map[x][y + 1] + Map[x - 1][y] + Map[x + 1][y]);

    // ㅜ
    if (x + 1 <= N && y - 1 >= 1 && y + 1 <= M)
        res = max(res, Map[x][y] + Map[x + 1][y] + Map[x][y - 1] + Map[x][y + 1]);

    // ㅗ
    if (x - 1 >= 1 && y - 1 >= 1 && y + 1 <= M)
        res = max(res, Map[x][y] + Map[x][y - 1] + Map[x][y + 1] + Map[x - 1][y]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j <= M ; ++j)
            cin >> Map[i][j];

    for (int i = 1 ; i <= N ; ++i){
        for (int j = 1 ; j <= M ; ++j){
            visited[i][j] = 1;
            DFS(i, j, 1, Map[i][j]);
            visited[i][j] = 0; // Backtracking
        }
    }

    cout << res << '\n';

    return 0;
}
