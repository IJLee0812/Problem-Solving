#include <iostream>
#include <string>
#define MAX 22
using namespace std;

struct Point{
    int x, y, dist;
};

char graph[MAX][MAX];
bool alphabet[26]; // idx 0: A ~ idx 25: Z

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int R, C, answer = 0;

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void input(){
    cin >> R >> C;
    for (int r = 0 ; r < R ; ++r){
        string str; cin >> str;
        for (int c = 0 ; c < C ; ++c){
            graph[r][c] = str[c];
        }
    }
}

void solve(Point curr){
    if (curr.dist > answer) answer = curr.dist;

    for (int i = 0 ; i < 4; ++i){
        int nx = curr.x + D[i][0], ny = curr.y + D[i][1];
        int next_index = graph[nx][ny] - 'A';

        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !alphabet[next_index]){
            alphabet[next_index] = true;
            solve({nx, ny, curr.dist + 1});
            alphabet[next_index] = false;
        }
    }
}

int main(){
    fastio();

    input();

    int start_index = graph[0][0] - 'A';
    alphabet[start_index] = true;
    solve({0, 0, 1}); // 시작점의 초기 dist == 1

    cout << answer;

    return 0;
}