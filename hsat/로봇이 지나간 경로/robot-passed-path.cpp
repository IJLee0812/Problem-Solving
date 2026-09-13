#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int H, W;
int D[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}}; // 두 칸씩. (D[i][0]) 0: 북 1: 남 2: 서 3: 동
vector<vector<char>> grid;
int total_hash_cnt = 0;

struct Point{
    int r, c, dir, visited_cnt; // dir 0: 북 1: 남 2: 서 3: 동
    string cmd;
};

int rotate_left(int curr_dir){
    if (curr_dir == 0) return 2;
    else if (curr_dir == 1) return 3;
    else if (curr_dir == 2) return 1;
    else if (curr_dir == 3) return 0;
    else return -1;
}

int rotate_right(int curr_dir){
    if (curr_dir == 0) return 3;
    else if (curr_dir == 1) return 2;
    else if (curr_dir == 2) return 0;
    else if (curr_dir == 3) return 1;
    else return -1;
}

int ans_r = 0, ans_c = 0, ans_dir = 0, ans_cmd_length = 25 * 25 + 1;
string ans_min_cmd;

char get_directions(int ans_dir){
    if (ans_dir == 0) return '^';
    else if (ans_dir == 1) return 'v';
    else if (ans_dir == 2) return '<';
    else if (ans_dir == 3) return '>';
    return ' ';
}

void BFS(int start_r, int start_c, int start_dir){
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    visited[start_r][start_c] = true;
    
    queue<Point> myqueue;
    myqueue.push({start_r, start_c, start_dir, 1, ""});

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

      
        if (curr.visited_cnt == total_hash_cnt){
            int curr_cmd_length = curr.cmd.length();

            if (ans_cmd_length > curr_cmd_length){
                ans_r = start_r + 1; // 1-based index
                ans_c = start_c + 1;
                ans_dir = start_dir;
                ans_cmd_length = curr_cmd_length;
                ans_min_cmd = curr.cmd;
            }
            else if (ans_cmd_length == curr_cmd_length){
                if (start_r + 1 > ans_r){
                    ans_r = start_r + 1;
                    ans_c = start_c + 1;
                    ans_dir = start_dir;
                    ans_min_cmd = curr.cmd;
                }
                else if (start_r + 1 == ans_r && start_c + 1 > ans_c){
                    ans_c = start_c + 1;
                    ans_dir = start_dir;
                    ans_min_cmd = curr.cmd;
                }
            }
            
            return;
        }

        for (int i = 0 ; i < 4 ; ++i){
            int nr = curr.r + D[i][0], nc = curr.c + D[i][1];
            int mr = curr.r + D[i][0] / 2, mc = curr.c + D[i][1] / 2; // 2칸 점프 시의 중간지점

            if (nr >= 0 && nr < H && nc >= 0 && nc < W){
                if (grid[mr][mc] == '#' && !visited[mr][mc] && grid[nr][nc] == '#' && !visited[nr][nc]){
                    string next_cmd = curr.cmd;

                    // 회전 먼저
                    if (i == rotate_left(curr.dir)) next_cmd += "L";
                    else if (i == rotate_right(curr.dir)) next_cmd += "R";
                    else if (i != curr.dir) continue;
                    
                    // 그다음 직진
                    next_cmd += "A";

                    // 방문처리
                    visited[mr][mc] = visited[nr][nc] = true;

                    // queue push
                    myqueue.push({nr, nc, i, curr.visited_cnt + 2, next_cmd});
                }
            }
        }
    }
}

int main() {
    fastio
    cin >> H >> W;

    grid.resize(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') total_hash_cnt++;
        }
    }

    for (int r = 0 ; r < H ; ++r)
        for (int c = 0 ; c < W ; ++c)
            if (grid[r][c] == '#')
                for (int dir = 0 ; dir < 4 ; ++dir) BFS(r, c, dir); // 각 위치/방향에 대한 독립적 BFS 실행으로 visited 중복사용 방지해야 함

    cout << ans_r << ' ' << ans_c << '\n' << get_directions(ans_dir) << '\n' << ans_min_cmd;

    return 0;
}
