/*
    입력
    5 -> 크기(정사각행렬)
    0 0 0 0 0
    0 0 0 1 1
    0 0 0 1 0 -> 0은 빈 공간, 1은 경계선
    1 1 1 1 0
    0 0 0 0 0
    1 1 3 -> 색칠 위치 시작 좌표(1, 1) / 3이라는 값으로 모두 색칠
*/

#include <iostream>
#include <stack>
#define MAX_N 10
using namespace std;

int N, num[MAX_N][MAX_N];

struct Point{
    int row, col;
};

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(int r, int c, int color){
    bool visited[MAX_N][MAX_N] = { false };
    stack<Point> mystack;
    mystack.push({r, c});
    while(!mystack.empty()){
        Point curr = mystack.top();
        mystack.pop();

        if (visited[curr.row][curr.col]) continue;
        visited[curr.row][curr.col] = true;
        num[curr.row][curr.col] = color;

        for (int i = 0 ; i < 4 ; ++i){
            int nr = curr.row + D[i][0];
            int nc = curr.col + D[i][1];

            if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
            if (visited[nr][nc]) continue;
            if (num[nr][nc] == 1) continue;
            mystack.push({nr, nc});
        }

    }
}

int main(){

    cin >> N;
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            cin >> num[i][j];
        }
    }

    int sr, sc, color;
    cin >> sr >> sc >> color;  

    DFS(sr, sc, color);

    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            cout << num[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
