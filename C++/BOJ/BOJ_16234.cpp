#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 52

using namespace std;

struct Point{
    int x, y;
};

int N, L, R, Graph[MAX][MAX], Border[MAX][MAX], curr_time = 0, D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool visited[MAX][MAX];

void input(){
    cin >> N >> L >> R;

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            cin >> Graph[i][j];
}

void init(){
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            Border[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

bool move(int i, int j, int mark){
    // 인접 나라 인구 차이가 L명 이상 R명 이하면 국경선 open
    queue<Point> myqueue;
    myqueue.push({i, j});
    visited[i][j] = true;
    Border[i][j] = mark;
    bool is_moved = false;

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

        for (int k = 0 ; k < 4 ; ++k){
            int nx = curr.x + D[k][0], ny = curr.y + D[k][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]){
                int diff = abs(Graph[nx][ny] - Graph[curr.x][curr.y]);

                if (L <= diff && diff <= R){
                    is_moved = true;
                    Border[nx][ny] = mark;
                    visited[nx][ny] = true;
                    myqueue.push({nx, ny});
                }
            }
        }
    }

    return is_moved;
}

void update(int mark){
    vector<int> pop_sum(mark + 1, 0), pop_cnt(mark + 1, 0);

    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            if (Border[i][j]){ 
                pop_sum[Border[i][j]] += Graph[i][j];
                pop_cnt[Border[i][j]]++;
            }
        }
    }

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            if (Border[i][j]) Graph[i][j] = pop_sum[Border[i][j]] / pop_cnt[Border[i][j]];
}

void simulation(){
    while (true){
        init();

        bool is_moved = false;
        int mark = 1;

        for (int i = 0 ; i < N ; ++i)
            for (int j = 0 ; j < N ; ++j)
                if (!visited[i][j] && move(i, j, mark++)) is_moved = true;
        
        if (!is_moved) break;

        update(mark);
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