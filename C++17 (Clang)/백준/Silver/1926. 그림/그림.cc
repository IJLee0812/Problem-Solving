#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 502

using namespace std;

int n, m;

int Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, paper_count = 0, max_area = 0;
bool visited[MAX][MAX];

struct Point{
    int x, y;
};

void input(){
    cin >> n >> m;

    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= m ; ++j)
            cin >> Graph[i][j];
}

int BFS(int i, int j){
    queue<Point> myqueue;
    myqueue.push({i, j});
    visited[i][j] = true;
    int curr_area = 1;

    while (!myqueue.empty()){
        Point curr = myqueue.front();

        myqueue.pop();

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && Graph[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = true;
                myqueue.push({nx, ny});
                curr_area++;
            }
        }
    }

    return curr_area;
}

void solve(){
    for (int i = 1 ; i <= n ; ++i){
        for (int j = 1 ; j <= m ; ++j){
            if (!visited[i][j] && Graph[i][j]){
                paper_count++;
                int area = BFS(i, j);
                max_area = max(max_area, area);
            }
        }
    }

    cout << paper_count << '\n';
    cout << max_area;
}

int main(){
    fastio
    input();
    solve();
    return 0;
}