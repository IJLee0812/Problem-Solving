/*

1. 2차원 <-> 1차원 인덱스 구성

e.g. 25개의 칸 <-> 0 ~ 24번까지의 1차원 배열

1차원 인덱스 -> 2차원 좌표: x = idx / 5, y = idx % 5;
2차원 좌표 -> 1차원 인덱스: idx = x * 5 + y;

int idx = 13;
int x = idx / 5; // 2
int y = idx % 5; // 3

*/

/*

2. 조합 (25C7 칠공주 조합)

*/
bool selected[25]; // 0 ~ 24번 학생 중 뽑힌 7명 true로 기록

int cases = 0;

void combination(int idx, int cnt, int s_cnt){
    // 종료조건
    if (cnt == 7){
        if (s_cnt >= 4)
            // 이다솜파가 4명 이상 -> BFS로 연결성 확인
            if (checkBFS()) cases++;

        return;
    }

    // 탐색: 'idx' 번 학생부터 24번 학생까지 순회하며 뽑기
    for (int i = idx ; i < 25 ; ++i){
        if (!selected[i]){
            selected[i] = true; // i번째 학생 뽑기

            int nx = i / 5, ny = i % 5;

            // 다음 인덱스 탐색 + Graph에 S = 1, Y = 0으로 저장했으므로, s_cnt 파라미터로 자동으로 갱신되어 넘어감
            combination(i + 1, cnt + 1, s_cnt + Graph[nx][ny]);
        
            // 백트래킹(원상복구)
            selected[i] = false;
        }
    }
}

/*

3. BFS 세팅방법(1차원 selected 배열과 매칭)
-> 뽑은 7명끼리만 길을 따라갔을 때, "7명이 다 만나는가?"

*/
bool checkBFS(){
    queue<Point> myqueue;
    bool visited[5][5];
    memset(visited, false, sizeof(visited));

    // 1. 큐에 넣을 '시작점' 찾기(뽑힌 7명 중 아무나)
    for (int i = 0 ; i < 25 ; ++i){
        if (selected[i]){
            // 1D to 2D
            int start_x = i / 5, start_y = i % 5;
            myqueue.push({start_x, start_y}); 
            visited[start_x][start_y] = true;
            break; // 시작점 찾았으므로 탈출
        }
    }

    int connected_cnt = 1; // 시작점 찾았으므로 1명 미리 카운트

    // 2. BFS로 칠공주 연결성 탐색
    while (!myqueue.empty()){
        Point curr = myqueue.front();
        
        myqueue.pop();

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visited[nx][ny]){
                if (selected[nx * 5 + ny]){ // 2D 좌표 -> 1D로 변환하여, 새로운 좌표가 선택된 칠공주 중 한 명인지 확인할 것.
                    visited[nx][ny] = true;
                    myqueue.push({nx, ny});
                    connected_cnt++;
                }
            }
        }
    }

    return (connected_cnt == 7);
}

int main(){
    // ...
    combination(0, 0, 0);
}
