#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 102

using namespace std;

struct Point{
    int x, y;
};

int Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, N, M, hour = 0, cheese_count = 0;

bool visited[MAX][MAX], isAllMelted = false;

vector<Point> melting_cheese_pieces;

void debug_graph(){
    cout << "\n\n" << "curr hour: " << hour << '\n';
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < M ; ++j){
            cout << Graph[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n\n";
}

void input(){
    cin >> N >> M; // N: 세로, M: 가로

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            cin >> Graph[i][j];
}

bool check(){
    queue<Point> myqueue;
    memset(visited, false, sizeof(visited));
    melting_cheese_pieces.clear();

    myqueue.push({0, 0});
    visited[0][0] = true;
    bool isExistCheese = false;

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]){
                visited[nx][ny] = true;
                
                if (!Graph[nx][ny]) myqueue.push({nx, ny});
                else{
                    isExistCheese = true;
                    melting_cheese_pieces.push_back({nx, ny});
                }
            }
        }
    }

    return isExistCheese;
}

void melt(){
    for (const auto& piece : melting_cheese_pieces) Graph[piece.x][piece.y] = 0;
}

void simulation(){
    int current_cheese = 0;
    
    // 치즈먼저 세기
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            if (Graph[i][j]) current_cheese++;

    if (!current_cheese){
        cout << hour << '\n' << cheese_count; // cheese_count: 1시간 전 치즈개수
        isAllMelted = true;
        return;
    }

    cheese_count = current_cheese; // 전역변수 갱신

    check();
    melt();
    // debug_graph();
    hour++;
}

int main(){
    fastio
    input();

    while (!isAllMelted) simulation();

    return 0;
}