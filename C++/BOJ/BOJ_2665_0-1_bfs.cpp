#include <iostream>
#include <deque>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 52

using namespace std;

int Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, N;

struct Point{
    int x, y, change_cnt;
};
bool visited[MAX][MAX];

void input(){
    cin >> N;
    string str;
    for (int i = 0 ; i < N ; ++i){
        cin >> str;
        for (int j = 0 ; j < N ; ++j) Graph[i][j] = str[j] - '0';
    }
}

void solve(){
    deque<Point> mydeque;

    mydeque.push_back({0, 0, 0});
    visited[0][0] = true;

    while (!mydeque.empty()){
        Point curr = mydeque.front();

        mydeque.pop_front();

        if (curr.x == N - 1 && curr.y == N - 1){
            cout << curr.change_cnt;
            return;
        }

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]){
                visited[nx][ny] = true;

                // 비용이 1인 길은 나중에 탐색(덱 뒤편)
                if (Graph[nx][ny] == 0) mydeque.push_back({nx, ny, curr.change_cnt + 1});
                
                // 비용이 0인 길은 빠르게 먼저 탐색(덱 앞에)
                else if (Graph[nx][ny] == 1) mydeque.push_front({nx, ny, curr.change_cnt});
                
            }
        }
    }
}

int main(){
    fastio 
    input();
    solve();
    return 0;
}
