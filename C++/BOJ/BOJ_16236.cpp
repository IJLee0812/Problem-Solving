#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 22
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int N;
bool visited[MAX][MAX];
int Space[MAX][MAX];
int D[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

struct Shark{
    int x, y;
    int size = 2;
    int eat_cnt = 0;
    int total_time = 0;
};

Shark shark;

// 큐에 넣을 탐색상태 및 먹이 후보 구조체
struct Info{
    int x, y, dist;
};

// custom compare 함수 정의
// 정렬 조건: 거리 동일 -> x가 작은 순(위) -> y가 작은 순(왼쪽)
bool compare(Info a, Info b){
    if (a.dist == b.dist){
        if (a.x == b.x) return a.y < b.y; // 하위
        return a.x < b.x;
    }

    return a.dist < b.dist; // 상위
}

void input(){
    cin >> N;

    for (int i = 1 ; i <= N ; ++i){
        for (int j = 1 ; j <= N ; ++j){
            cin >> Space[i][j];
            if (Space[i][j] == 9){
                shark.x = i, shark.y = j;
                
                Space[i][j] = 0; // (중요) 상어가 있던 자리는 빈칸으로 초기화해야 함
            }
        }
    }
}

// 1번의 사냥을 수행(먹이 먹었으면 true, 못 찾았으면 false)
bool hunt(){
    queue<Info> q;
    vector<Info> candidates; // 먹을 수 있는 물고기 후보들

    memset(visited, false, sizeof(visited)); // 매 사냥마다 초기화.

    q.push({shark.x, shark.y, 0});
    visited[shark.x][shark.y] = true;

    int min_dist = 1e9; // 최단 거리 저장용

    while (!q.empty()){
        int curr_x = q.front().x, curr_y = q.front().y, curr_dist = q.front().dist;
        q.pop();

        // 이미 찾은 최단거리보다 더 멀리 탐색할 필요 X. 필터링 로직 
        if (curr_dist >= min_dist) continue;

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr_x + D[i][0], ny = curr_y + D[i][1];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny]){
                // 1. 지나갈 수 있는 경우 (빈칸이거나, 물고기가 상어 크기 이하)
                if (Space[nx][ny] <= shark.size){
                    visited[nx][ny] = true;

                    // 2. 먹을 수 있는 경우 (빈칸이 아니고, 상어보다 작은 물고기)
                    if (Space[nx][ny] > 0 && Space[nx][ny] < shark.size){
                        min_dist = curr_dist + 1; // 최단거리 갱신
                        candidates.push_back({nx, ny, min_dist}); // 후보 리스트에 추가
                    }
                    else{
                        // 3. 먹을 수 없고 지나가기만 하는 경우
                        q.push({nx, ny, curr_dist + 1});
                    }
                }
                
            }
        }
    }

    // 먹을 수 있는 물고기를 하나도 못 찾은 경우
    if (candidates.empty()) return false;

    // 후보 리스트 정렬
    sort(candidates.begin(), candidates.end(), compare);

    // 1등 물고기 정보 가져오기
    Info target = candidates[0];

    // 상어 상태 업데이트
    shark.x = target.x;
    shark.y = target.y;
    shark.total_time += target.dist;
    Space[target.x][target.y] = 0; // (중요) 물고기 먹었으므로 0으로 만들어줘야 함

    shark.eat_cnt++;

    if (shark.eat_cnt == shark.size){
        shark.size++;
        shark.eat_cnt = 0;
    }

    return true; // 사냥 성공
}

void solve(){
    // 먹이 찾을 수 있을 때까지 시뮬레이션
    while (true) if (!hunt()) break;

    cout << shark.total_time << '\n';
}

int main(){
    fastio
    input();
    solve();
    return 0;
}