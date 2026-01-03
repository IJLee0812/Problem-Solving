#include <bits/stdc++.h>
using namespace std;

int N, M, paper[501][501], res = 0, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool visited[501][501];

void DFS(int x, int y, int cnt, int curSum){
    if (cnt == 4){
        if (res < curSum) res = curSum;
        return;
    }

    for (int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]){
            visited[nx][ny] = true;
            DFS(nx, ny, cnt + 1, curSum + paper[nx][ny]);
            visited[nx][ny] = false;
        }
    }

    if(y - 1 >= 0 && y + 1 < M && x - 1 >= 0){ // ㅗ
        res = max(res, paper[x][y] + paper[x][y - 1] + paper[x][y + 1] + paper[x - 1][y]);
    }

    if(y + 1 < M && x - 1 >= 0 && x + 1 < N){ // ㅏ
        res = max(res, paper[x][y] + paper[x][y + 1] + paper[x - 1][y] + paper[x + 1][y]);
    }

    if(y - 1 >= 0 && y + 1 < M && x + 1 < N){ // ㅜ
        res = max(res, paper[x][y] + paper[x][y - 1]+ paper[x + 1][y] + paper[x][y + 1]);
    }

    if(y - 1 >= 0 && x - 1 >= 0 && x + 1 < N){ // ㅓ
        res = max(res, paper[x][y] + paper[x][y - 1] + paper[x - 1][y] + paper[x + 1][y]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            cin >> paper[i][j];

    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            if (!visited[i][j]){
                visited[i][j] = true;
                DFS(i, j, 1, paper[i][j]);
                visited[i][j] = false; // backtracking
            }
        }
    }

    cout << res;

    return 0;
}