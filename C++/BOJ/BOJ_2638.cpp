#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define MAX 102

using namespace std;

int N, M, D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, hour = 0; 
vector<vector<int>> Graph;
bool isAir[MAX][MAX];

struct Point{
    int x, y;
};

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void input(){
    cin >> N >> M;
    Graph.resize(N, vector<int>(M));
    for (int n = 0 ; n < N ; ++n){
        for (int m = 0 ; m < M ; ++m){
            cin >> Graph[n][m];
        }
    }
}

// 외부 공기 판별 BFS
void checkAir(){
    // [수정] 매 시간 새로 계산하므로, 초기화 필수
    memset(isAir, false, sizeof(isAir));

    queue<Point> myqueue;
    myqueue.push({0, 0});
    isAir[0][0] = true;

    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                if (Graph[nx][ny] == 0 && !isAir[nx][ny]){
                    isAir[nx][ny] = true;
                    myqueue.push({nx, ny});
                }
            }
        }
    }
}

// 시뮬레이션 
void solve(){
    // 시뮬레이션 루프 안에서, 매 시간마다 매번 checkAir 다시 진행해줘야 함
    while (true){
        // 1. 이번 시간의 외부 공기 판별 진행
        checkAir();

        vector<Point> meltingList; // [수정] 녹을 치즈 목록

        // 2. 모든 치즈 검사 진행
        for (int i = 0 ; i < N ; ++i){
            for (int j = 0 ; j < M ; ++j){
                if (Graph[i][j] == 1){
                    int cnt = 0;
                    for (int k = 0 ; k < 4 ; ++k){
                        int nx = i + D[k][0], ny = j + D[k][1];

                        // [수정] 반드시 '외부 공기(isAir)'와 접촉한 것만 카운트
                        if (isAir[nx][ny]) cnt++;
                    }

                    if (cnt >= 2) meltingList.push_back({i, j});
                }
            }
        }

        // 3. 녹을 치즈가 없다면, 시뮬레이션 종료.
        if (meltingList.empty()) break;

        // 4. 치즈 한 번에 녹이기
        // 이번 시간에 녹을 치즈들의 좌표를 따로 vector에 담아두고, 검사 모두 완료 후 한 번에 녹여야 인접 값에 영향 안받음
        for (Point p : meltingList) Graph[p.x][p.y] = 0;

        // 5. 시간 증가
        hour++;
    }

    cout << hour;
}

int main(){
    fastio();
    input();
    solve();
    return 0;
}