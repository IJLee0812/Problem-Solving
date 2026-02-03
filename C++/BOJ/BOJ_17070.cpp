#include <iostream>
#include <queue>
#include <string> // string 사용을 위해 추가
#define MAX 20

using namespace std;

int N, Graph[MAX][MAX];

struct Point{
    int x, y;
};

struct Pipe{
    Point start;
    Point end;
};

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void input(){
    cin >> N;
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            cin >> Graph[i][j];
}

string calculate_direction(Pipe pipe){
    Point curr_start = pipe.start;
    Point curr_end = pipe.end;

    // 가로 
    if (curr_start.x == curr_end.x) return "horizontal";
    
    // 세로 
    else if (curr_start.y == curr_end.y) return "vertical";
    
    // 대각선
    else return "diagonal";
}

int BFS(){
    int method_count = 0;

    queue<Pipe> myqueue;

    myqueue.push({{0, 0}, {0, 1}});

    while (!myqueue.empty()){
        Pipe curr = myqueue.front();
        myqueue.pop();

        if (curr.end.x == N - 1 && curr.end.y == N - 1){
            method_count++;
            continue;
        }

        string direction = calculate_direction(curr);

        if (direction == "horizontal"){ 
            // 1. 오른쪽 이동 
            if (curr.end.y + 1 < N && Graph[curr.end.x][curr.end.y + 1] != 1){
                myqueue.push({{curr.end.x, curr.end.y}, {curr.end.x, curr.end.y + 1}});
            }

            // 2. 대각선 이동 
            if (curr.end.x + 1 < N && curr.end.y + 1 < N) {
                if (Graph[curr.end.x][curr.end.y + 1] != 1 &&     // 오른쪽
                    Graph[curr.end.x + 1][curr.end.y] != 1 &&     // 아래
                    Graph[curr.end.x + 1][curr.end.y + 1] != 1) { // 대각선
                    
                    myqueue.push({{curr.end.x, curr.end.y}, {curr.end.x + 1, curr.end.y + 1}});
                }
            }
        }
        // 현재 세로 상태일 때
        else if (direction == "vertical"){ 
            // 1. 아래 이동
            if (curr.end.x + 1 < N && Graph[curr.end.x + 1][curr.end.y] != 1){
                myqueue.push({{curr.end.x, curr.end.y}, {curr.end.x + 1, curr.end.y}});
            }

            // 2. 대각선 이동
            if (curr.end.x + 1 < N && curr.end.y + 1 < N){
                if (Graph[curr.end.x][curr.end.y + 1] != 1 && 
                    Graph[curr.end.x + 1][curr.end.y] != 1 && 
                    Graph[curr.end.x + 1][curr.end.y + 1] != 1){
                    myqueue.push({{curr.end.x, curr.end.y}, {curr.end.x + 1, curr.end.y + 1}});
                }
            }
        }
        // 현재 대각선 상태일 때
        else{ 
            // 1. 가로
            if (curr.end.y + 1 < N && Graph[curr.end.x][curr.end.y + 1] != 1){
                myqueue.push({{curr.end.x, curr.end.y}, {curr.end.x, curr.end.y + 1}});
            }
            
            // 2. 세로
            if (curr.end.x + 1 < N && Graph[curr.end.x + 1][curr.end.y] != 1){
                myqueue.push({{curr.end.x, curr.end.y}, {curr.end.x + 1, curr.end.y}});
            }

            // 3. 대각선 
            if (curr.end.x + 1 < N && curr.end.y + 1 < N) {
                if (Graph[curr.end.x][curr.end.y + 1] != 1 && 
                    Graph[curr.end.x + 1][curr.end.y] != 1 && 
                    Graph[curr.end.x + 1][curr.end.y + 1] != 1) {
                    
                    myqueue.push({{curr.end.x, curr.end.y}, {curr.end.x + 1, curr.end.y + 1}});
                }
            }
        }
    }

    return method_count;
}

void solve(){
    int sol = BFS();
    cout << sol;
}

int main(){
    fastio();
    input();
    solve();
    return 0;
}