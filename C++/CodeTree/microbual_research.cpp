#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define MAX 16
#define MAXQ 51

using namespace std;

int T;
int N, Q;
int MAP[MAX][MAX];
bool visited[MAX][MAX];

struct Point{
    int r;
    int c;
};
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Query{
    int r1;
    int c1;
    int r2;
    int c2;
};
Query query[MAXQ];

struct Micro{
    int id;     // 미생물의 id
    int minR;
    int minC;
    int maxC;
    int maxR;
    int area;  // 미생물 영역 넓이
};
Micro micros[MAXQ];
int mcnt;           // 살아있는 미생물의 개수 관리

bool dead[MAXQ];    // 미생물의 id를 이용하여 생존 여부를 관리(dead / alive)

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}

void input(){
    cin >> N >> Q;
    for (int q = 1 ; q <= Q ; ++q){
        cin >> query[q].r1 >> query[q].c1 >> query[q].r2 >> query[q].c2;
    }
}

// (r1, c1) ~ (r2 - 1, c2 - 1): 1을 뺀 만큼 투입해야 함
void insert(int id, int r1, int c1, int r2, int c2){
    for (int r = r1 ; r < r2 ; ++r){
        for (int c = c1 ; c < c2 ; ++c){
            MAP[r][c] = id;
        }
    }
}

Micro BFS(int r, int c){
    int minR, minC, maxR, maxC, area = 0;
    queue<Point> myqueue;
    myqueue.push({r, c});
    visited[r][c] = true;
    area++;

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

        for (int i = 0 ; i < 4 ; ++i){
            int nr = curr.r + D[i][0];
            int nc = curr.c + D[i][1];

            // id가 다른 미생물이거나 || 기 탐색 완료했던 미생물인 경우 다음 탐색을 진행한다.
            if (MAP[curr.r][curr.c] != MAP[nr][nc] || visited[nr][nc]) continue;

            myqueue.push({nr, nc});
            visited[nr][nc] = true;
            area++;

            // 좌표 min/max 지점 업데이트
            if (nr < minR) minR = nr;
            if (nc < minC) minC = nc;
            if (nr > maxR) maxR = nr;
            if (nc > maxC) maxC = nc;
        }
    }

    Micro ret = { 0 };

    ret.id = MAP[r][c];
    ret.minR = minR;
    ret.minC = minC;
    ret.maxR = maxR;
    ret.maxC = maxC;
    ret.area = area;

    return ret;
}

void findLiveMicro(){
    // micro 배열의 인덱스(살아있는 미생물의 인덱스 관리)
    mcnt = 0; 
    // visited 배열 초기화
    for (int r = 0 ; r <= N ; ++r){
        for (int c = 0 ; c <= N ; ++c){
            visited[r][c] = false;
        }
    }

    bool check[MAXQ] = { false }; // 미생물 사망/생존 정보 저장
    for (int r = 0 ; r < N ; ++r){ // 0 ~ N - 1
        for (int c = 0 ; c < N ; ++c){
            int id = MAP[r][c];

            if (id == 0 || dead[id] == true || visited[r][c] == true) continue;

            Micro m = BFS(r, c);

            // check[미생물id] == true => 해당 미생물은 두 개로 분리되었으므로 사망처리 필요
            if (check[id] == true){
                dead[id] = true;
                continue;
            }

            check[id] = true;
            micros[mcnt++] = m;

        }
    }

    // - - - 살아있는 미생물만 micros 배열에 재정리 - - -
    int temp = mcnt;

    mcnt = 0; // 재정리를 위한 개수 초기화

    for (int i = 0 ; i < temp ; ++i){
        if (dead[micros[i].id]) continue;

        micros[mcnt++] = micros[i]; // micros 배열에 최종 저장
    }
}

// a가 우선순위가 더 높을 시 true
bool isPriority(Micro a, Micro b){
    // 넓은 면적 우선선택
    if (a.area != b.area) return a.area > b.area;

    return a.id < b.id;
}

void sortMicro(){
    for (int i = 0 ; i < mcnt - 1 ; ++i){
        for (int k = i + 1 ; k < mcnt ; ++k){
            if (!isPriority(micros[i], micros[k])){
                Micro temp = micros[i];
                micros[i] = micros[k];
                micros[k] = temp;
            }
        }
    }
}

bool checkMove(int newMAP[MAX][MAX], Micro m, int fr, int fc){
    int sr = m.minR;
    int sc = m.minC;
    int er = m.maxR;
    int ec = m.maxC;

    for (int r = sr ; r <= er ; ++r){
        for (int c = sc ; c <= ec ; ++c){
            // 다른 미생물인 경우 || 빈 공간(0)인 경우 무시
            if (MAP[r][c] != m.id || MAP[r][c] == 0) continue;

            int newR = fr - sr + r;
            int newC = fc - sc + c;

            // 격자 밖을 넘어가는 경우
            if (newR >= N || newC >= N) return false;

            // 새 용기에 이미 다른 생물이 있는 경우
            if (newMAP[newR][newC] != 0) return false;
        }
    }

    return true;
}

void actualMove(int newMAP[MAX][MAX], Micro m, int fr, int fc){
    int sr = m.minR;
    int sc = m.minC;
    int er = m.maxR;
    int ec = m.maxC;

    for (int r = sr ; r <= er ; ++r){
        for (int c = sc ; c <= ec ; ++c){
            if (MAP[r][c] != m.id || MAP[r][c] == 0) continue;

            int newR = fr - sr + r;
            int newC = fc - sc + c;
            newMAP[newR][newC] = m.id;
        }
    }
}

void moveMicro(int newMAP[MAX][MAX], Micro m){
    for (int r = 0 ; r <= N ; ++r){
        for (int c = 0 ; c <= N ; ++c){
            if (checkMove(newMAP, m, r, c)){
                actualMove(newMAP, m, r, c);
                return;
            }
        }
    }
}

// 새 배양 용기(newMAP)에 살아있는 미생물을 순서대로 옮김
// 모두 옮긴 후, 새 배양 용기를 기존 배양 용기(MAP)에 복사
void moveAllMicro(){
    int newMAP[MAX][MAX] = { 0 };

    // 순서대로 살아있는 미생물을 옮김
    for (int i = 0 ; i < mcnt ; ++i) moveMicro(newMAP, micros[i]);

    // 기존 배양 용기에 새 배양 용기를 복사함
    for (int r = 0 ; r < N ; ++r){
        for (int c = 0 ; c < N ; ++c){
            MAP[r][c] = newMAP[r][c];
        }
    }
}

int getArea(int id){
    for (int i = 0 ; i < mcnt ; ++i){
        if (micros[i].id == id) return micros[i].area;
    }
    return -1;
}

int getScore(int maxID){
    // 인접행렬
    int company[MAXQ][MAXQ] = { 0 };

    for (int r = 0 ; r <= N ; ++r){
        for (int c = 0 ; c <= N ; ++c){
            if (MAP[r][c] == 0) continue;

            for (int i = 0 ; i < 4 ; ++i){
                int nr = r + D[i][0];
                int nc = c + D[i][1];

                int id1 = MAP[r][c];
                int id2 = MAP[nr][nc];

                if (id1 == id2 || id2 == 0) continue;

                company[id1][id2] = true;
                company[id2][id1] = true;
            }
        }
    }

    int score = 0;

    for (int i = 1 ; i <= maxID - 1 ; ++i){
        for (int k = i + 1 ; k <= maxID ; ++k){
            if (company[i][k] == false) continue; // 인접한 경우에만 둘의 면적을 곱한 값을 score에 추가

            int area1 = getArea(i);
            int area2 = getArea(k);

            score += (area1 * area2);
        }
    }

    return score;
}

void simulate(){
    for (int id = 1 ; id <= Q ; ++id){
        int r1, c1, r2, c2;
        r1 = query[id].r1;
        c1 = query[id].c1;
        r2 = query[id].r2;
        c2 = query[id].c2;
        
        // 미생물 투입
        insert(id, r1, c1, r2, c2);

        // 배양 용기 이동
        findLiveMicro();
        sortMicro();
        moveAllMicro();

        // 실험 결과 기록
        cout << getScore(id) << '\n';
    }
}

int main(){
    fastio();
    input();
    simulate();
    return 0;
}