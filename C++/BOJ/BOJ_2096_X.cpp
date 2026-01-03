#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100002
using namespace std;

int N, max_score = 0, min_score = 123456789;

int graph[MAX][3];

struct Point{
    int x, y, score;
};

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void input(){
    cin >> N;
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < 3 ; ++j){
            cin >> graph[i][j];
        }
    }
}

void solve(Point curr){ // 상태관리 효율화방안 모색
    if (curr.x < N - 1){
        if (curr.y == 0){
            solve({curr.x + 1, curr.y, curr.score + graph[curr.x + 1][curr.y]});
            solve({curr.x + 1, curr.y + 1, curr.score + graph[curr.x + 1][curr.y + 1]});
        }
        else if (curr.y == 1){
            solve({curr.x + 1, curr.y - 1, curr.score + graph[curr.x + 1][curr.y - 1]});
            solve({curr.x + 1, curr.y, curr.score + graph[curr.x + 1][curr.y]});
            solve({curr.x + 1, curr.y + 1, curr.score + graph[curr.x + 1][curr.y + 1]});
        }
        else{
            solve({curr.x + 1, curr.y - 1, curr.score + graph[curr.x + 1][curr.y - 1]});
            solve({curr.x + 1, curr.y, curr.score + graph[curr.x + 1][curr.y]});
        }
    }

    // curr.x == N - 1. 즉 마지막 줄 도달 시 점수 갱신
    if (curr.x == N - 1){
        if (max_score < curr.score) max_score = curr.score;
        if (min_score > curr.score) min_score = curr.score;
    }
}


int main(){
    fastio();
    input();

    solve({0, 0, graph[0][0]});
    solve({0, 1, graph[0][1]});
    solve({0, 2, graph[0][2]});

    cout << max_score << " " << min_score;

    return 0;
}