#include <iostream>
#include <queue>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 12

using namespace std;

int Board[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
/* 
    [Board Spec]

    - 1-based 인덱싱

    '.' -> 0 (빈 칸)
    '#' -> -1 (벽)
    'O(alphabet O)' -> 1 (구멍)
    'R' -> 2 (빨간 구슬)
    'B' -> 3 (파란 구슬)
*/

struct Point{
    int x, y;
};

int N, M;

void debug_board(){
    cout << "\n\n=====board=====\n";
    for (int i = 1 ; i <= N ; ++i){
        for (int j = 1 ; j <= M ; ++j){
            cout << Board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n\n=====board=====\n";
}

void input(){
    string str;

    cin >> N >> M; // N(i): 세로, M(j): 가로

    for (int i = 1 ; i <= N ; ++i){
        cin >> str;
        for (int j = 1 ; j <= M ; ++j){
            char ch = str[j - 1];

            if (ch == '.'){
                Board[i][j] = 0;
            }
            else if (ch == '#'){
                Board[i][j] = -1;
            }
            else if (ch == 'O'){
                Board[i][j] = 1;
            }
            else if (ch == 'R'){
                Board[i][j] = 2;
            }
            else if (ch == 'B'){
                Board[i][j] = 3;
            }
        }
    }
}

bool move_left(){

}

bool move_right(){
    
}

bool move_upward(){
    
}

bool move_downward(){
    
}

void restore(){

}

void BFS(Point red_loc, Point blue_loc){

}

void solve(){
    // debug_board();



}

int main(){
    fastio
    input();
    solve();
    return 0;
}