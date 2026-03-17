#include <iostream>
#include <queue>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 302

using namespace std;

int l, tc;
bool visited[MAX][MAX];

struct Point{
    int x, y, cnt;
};

int d[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void solve(){
    cin >> l;
    Point start, end;
    cin >> start.x >> start.y >> end.x >> end.y;

    if (start.x == end.x && start.y == end.y){
        cout << 0 << '\n';
        return;
    }

    queue<Point> myqueue;
    memset(visited, false, sizeof(visited));

    myqueue.push({start.x, start.y, 0});
    visited[start.x][start.y] = true;

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

        for (int i = 0 ; i < 8 ; ++i){
            int nx = curr.x + d[i][0], ny = curr.y + d[i][1];

            if (nx < 0 || nx >= l || ny < 0 || ny >= l || visited[nx][ny]) continue;

            if (nx == end.x && ny == end.y){
                cout << curr.cnt + 1 << '\n';
                return;
            }

            visited[nx][ny] = true;
            myqueue.push({nx, ny, curr.cnt + 1});
        }
    }
}

int main(){
    fastio
    cin >> tc;
    while (tc--) solve();
    return 0;
}