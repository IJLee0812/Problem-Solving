#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 52

using namespace std;

struct Point{
    int x, y;
};

int N, L, R, Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, curr_time = 0;

bool visited[MAX][MAX];

void input(){
    cin >> N >> L >> R;

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            cin >> Graph[i][j];
}

void init(){
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            visited[i][j] = false;
}

bool bfs(int i, int j){
    // 인접 나라 인구 차이가 L명 이상 R명 이하면 국경선 open
    queue<Point> myqueue;
    vector<Point> united; // 연합에 속할 좌표들을 저장할 벡터

    myqueue.push({i, j});
    united.push_back({i, j});
    visited[i][j] = true;

    int sum = Graph[i][j]; // 연합의 총 인구수 누적.

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

        for (int k = 0 ; k < 4 ; ++k){
            int nx = curr.x + D[k][0], ny = curr.y + D[k][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]){
                int diff = abs(Graph[nx][ny] - Graph[curr.x][curr.y]);

                if (L <= diff && diff <= R){
                    visited[nx][ny] = true;
                    myqueue.push({nx, ny});
                    united.push_back({nx, ny});
                    sum += Graph[nx][ny];
                }
            }
        }
    }

    if (united.size() == 1) return false;

    int result = sum / united.size();
    for (auto p : united) Graph[p.x][p.y] = result;
    return true;
}

void simulation(){
    while (true){
        init();
        bool is_moved = false;

        for (int i = 0 ; i < N ; ++i)
            for (int j = 0 ; j < N ; ++j)
                if (!visited[i][j] && bfs(i, j)) is_moved = true;
        
        if (!is_moved) break;

        curr_time++;
    }

    cout << curr_time;
}

int main(){
    fastio
    input();
    simulation();
    return 0;
}