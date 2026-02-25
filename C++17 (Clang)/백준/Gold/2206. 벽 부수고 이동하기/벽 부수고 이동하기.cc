#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int N, M, graph[MAX][MAX], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool visited[MAX][MAX][2]; // 0 : 벽을 부수지 않음, 1 : 벽을 부숨 => 이미 방문했던 정점이라도, 벽을 부수고 왔는지 부수지 않고 왔는지는 서로 다른 경로로 취급해야 하므로 두 가지의 방문가능경우를 처리하기 위함

int solve(){
    queue<pair<pair<int, int>, pair<int, int>>> q; // {x좌표, y좌표, 벽 부순 횟수(0 or 1), 누적 거리}
    q.push({{0, 0}, {0, 1}});
    visited[0][0][0] = true;

    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int B = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (x == N - 1 && y == M - 1)
            return cnt; // 정상종료 조건
        

        for (int i = 0 ; i < 4 ; ++i){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M){ // 범위 체크

                if (graph[nx][ny] == 1 && B == 0){ // 이동하려는 다음 칸이 벽이고, 벽을 아직 부수지 않았다면 (B == 1 인 경우는 이미 벽을 한 번 부순 경우이므로, 큐에 넣어주지 않으면 됨.)
                    visited[nx][ny][B + 1] = true;
                    q.push({{nx, ny}, {B + 1, cnt + 1}});
                }

                else if (graph[nx][ny] == 0 && !visited[nx][ny][B]){
                    visited[nx][ny][B] = true;
                    q.push({{nx, ny}, {B, cnt + 1}});
                }
            }
        }
    }

    return -1; // while문 탈출
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0 ; i < N ; ++i){
        string str; cin >> str;
        for (int j = 0 ; j < M ; ++j)
            graph[i][j] = str[j] - '0';
    }

    cout << solve();

    return 0;
}