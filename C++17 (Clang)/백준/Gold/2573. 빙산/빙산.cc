#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 302

using namespace std;

int N, M, Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, year = 0;

bool visited_check[MAX][MAX];

struct Point{
    int x, y;
};

void debug_graph(){
    cout << "\n\ncurr_year: " << year << "\n\n";

    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            cout << Graph[i][j] << ' ';
        }
        cout << "\n\n";
    }
}

void input(){
    cin >> N >> M;

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            cin >> Graph[i][j];
}

void checkBFS(int i, int j){
    queue<Point> myqueue;
    myqueue.push({i, j});
    visited_check[i][j] = true;

    while (!myqueue.empty()){
        Point curr = myqueue.front();

        myqueue.pop();

        for (int k = 0 ; k < 4 ; ++k){
            int nx = curr.x + D[k][0], ny = curr.y + D[k][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && Graph[nx][ny] > 0 && !visited_check[nx][ny]){
                myqueue.push({nx, ny});
                visited_check[nx][ny] = true;
            }
        }
    }
}

int melt(int x, int y){
    int melt_amount = 0;
    for (int i = 0 ; i < 4 ; ++i){
        int nx = x + D[i][0], ny = y + D[i][1];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && (Graph[nx][ny] == 0)) melt_amount++;        
    }

    return melt_amount;
}

void simulation(){
    // 동시성 처리 필요(1이 녹아서 0이 되도, 같은 년도에는 옆 빙산조각한테 반영되면 안 됨)
    queue<pair<Point, int>> myqueue;

    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            if (Graph[i][j] > 0){
                int melt_amount = melt(i, j);
                myqueue.push({{i, j}, melt_amount});
            }
        }
    }

    while(!myqueue.empty()){
        Point curr = myqueue.front().first;
        int melt_amount = myqueue.front().second;
        
        myqueue.pop();

        // 깎인 빙산 높이가 음수가 되면 안 됨.
        Graph[curr.x][curr.y] = max(0, Graph[curr.x][curr.y] - melt_amount);
    }
}

int main(){
    fastio
    input();

    while (true){
        memset(visited_check, false, sizeof(visited_check));

        int component_cnt = 0; // 덩어리 개수

        for (int i = 0 ; i < N ; ++i){
            for (int j = 0 ; j < M ; ++j){
                if (Graph[i][j] > 0 && !visited_check[i][j]){
                    checkBFS(i, j);
                    component_cnt++;
                }
            }
        }

        if (component_cnt >= 2){
            cout << year;
            return 0;
        }

        if (component_cnt == 0){
            cout << '0';
            return 0;
        }

        // 체크 완료되면, 녹이기 시뮬레이션
        simulation();
        year++;
        // debug_graph();
    }

    return 0;
}