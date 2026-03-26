#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define INF 1e9
#define MAX 102
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int Graph[MAX][MAX];

struct Point{
    int x, y;
};

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, M, N;

int dist[MAX][MAX];

void input(){
    cin >> M >> N; // M: 가로, N: 세로
    string tmp;
    for (int i = 1 ; i <= N ; ++i){
        cin >> tmp;
        for (int j = 1 ; j <= M ; ++j) Graph[i][j] = tmp[j - 1] - '0';

    }
}

void init_dist(){
    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j <= M ; ++j)
            dist[i][j] = INF;
}

void solve(){
    deque<Point> mydeque;

    init_dist();

    mydeque.push_back({1, 1});
    dist[1][1] = 0;

    while (!mydeque.empty()){
        Point curr = mydeque.front();

        mydeque.pop_front();

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M){
                if (Graph[nx][ny] == 1){ // 벽 뚫기
                    if (dist[nx][ny] > 1 + dist[curr.x][curr.y]){
                        dist[nx][ny] = 1 + dist[curr.x][curr.y];
                        mydeque.push_back({nx, ny}); // 비용이 늘었으니, 맨 뒤에 줄세움
                    }
                }
                else{ // 벽 안 뚫기
                    if (dist[nx][ny] > dist[curr.x][curr.y]){
                        dist[nx][ny] = dist[curr.x][curr.y];
                        mydeque.push_front({nx, ny}); // 비용이 그대로니, 맨 앞으로 보내도 됨
                    }
                }
            }
        }
    }

    cout << dist[N][M];
}

int main(){
    fastio
    input();
    solve();
    return 0;
}
