#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

// to use bitwise or(|)
#define MINT (1)
#define CHOCO (10)
#define MILK (100)
#define MINTCHOCO (11)
#define MINTMILK (101)
#define CHOCOMILK (110)
#define MINTCHOCOMILK (111)
#define UP (0)
#define DOWN (1)
#define LEFT (2)
#define RIGHT (3)
#define MAX 55

using namespace std;

struct STUDENT{
    int food;
    int believe;
    int r;
    int c;
    bool leader;
    int defense;
};

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N, T;
char F[MAX][MAX];
int B[MAX][MAX];

STUDENT student[MAX][MAX];      // 좌표 정보 저장할 공간(2차원 배열)
bool visited[MAX][MAX];         // 방문 여부 표시

STUDENT candidates[MAX * MAX];  // 리더 후보자 저장할 공간(1차원 배열)
int ccnt = 0;                   // candidates 배열 전용 인덱스

// 각 그룹들을 저장할 배열(그룹 1 / 2 / 3)
STUDENT group[4][MAX * MAX]; 
// 각 그룹별 학생들을 순회할 때 사용하는 인덱스
int indexArr[4]; 

struct Point{
    int r;
    int c;
};
queue<Point> myqueue;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}

void input(){
    cin >> N >> T;
    string temp;

    for (int r = 1 ; r <= N ; ++r){
        cin >> temp;
        for (int c = 1 ; c <= N ; ++c){
            F[r][c] = temp[c - 1];
        }
    }

    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            cin >> B[r][c];
        }
    }

    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            student[r][c].believe = B[r][c];
            student[r][c].r = r;
            student[r][c].c = c;
            student[r][c].defense = 0; // init defense
            student[r][c].leader = false;

            if (F[r][c] == 'T') student[r][c].food = MINT;
            else if (F[r][c] == 'M') student[r][c].food = MILK;
            else if (F[r][c] == 'C') student[r][c].food = CHOCO;
        }
    }
}

void process_morning(){
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            student[r][c].believe++;
        }
    }
}

bool isPriority(STUDENT a, STUDENT b){
    if (a.believe != b.believe) return a.believe > b.believe;
    if (a.r != b.r) return a.r < b.r;
    return a.c < b.c;
}

void BFS(int r, int c){
    myqueue.push({r, c});
    visited[r][c] = true;

    // 리더 후보자 선정을 위한 배열 인덱스 초기화
    ccnt = 0;
    candidates[ccnt++] = student[r][c];

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();

        for (int i = 0 ; i < 4 ; ++i){
            int nr = curr.r + D[i][0];
            int nc = curr.c + D[i][1];

            if (nr < 1 || nr > N || nc < 1 || nc > N) continue; // 범위초과

            if (visited[nr][nc]) continue; // 기 방문지점

            if (student[curr.r][curr.c].food != student[nr][nc].food) continue; // 같은 음식일 때만 grouping

            myqueue.push({nr, nc});
            visited[nr][nc] = true;

            candidates[ccnt++] = student[nr][nc];
        }
    }

    // - - - 그룹 리더 부여과정 - - - 

    STUDENT leader = { 0 }; // 구조체 init
    
    // 우선순위 기준에 따른 리더 부여
    for (int i = 0 ; i < ccnt ; ++i){
        if (isPriority(candidates[i], leader) == true){
            leader = candidates[i];
        }
    }

    // 구조체에 리더 정보 반영
    student[leader.r][leader.c].leader = true;
    student[leader.r][leader.c].believe += (ccnt - 1); // (그룹원 수 - 1) 만큼 신앙심 추가

    // (중요) 리더 말고 나머지 그룹원들은 신앙심 1씩 감소시킴
    for (int i = 0 ; i < ccnt ; ++i){
        STUDENT curr = candidates[i];

        if (curr.r == leader.r && curr.c == leader.c) continue;

        student[curr.r][curr.c].believe--;
    }
}

void process_lunch(){
    // 1. 방문 정보 및 리더 여부 초기화
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            student[r][c].leader = false;
            visited[r][c] = false;
        }
    }

    // 2. BFS로 Grouping 진행
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            if (visited[r][c] == true) continue;

            BFS(r, c);
        }
    }
}

// 그룹 번호 getter
int getGroupNumber(int food){
    if (food == MINTCHOCOMILK) return 3;
    if (food == MINT || food == CHOCO || food == MILK) return 1;
    return 2;
}

int mixFood(int sFood, int nFood){ // s == 전파자, n == 새로운 전파 대상
    return sFood | nFood;
}

void process_dinner(){
    // 그룹 인덱스 초기화
    for (int g = 1 ; g <= 3 ; ++g){
        indexArr[g] = 0;
    }

    // 리더인 학생을 찾고, 해당 학생의 음식을 보고 그룹을 나눔
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            STUDENT s = student[r][c];

            if (s.leader == false) continue;

            int groupNumber = getGroupNumber(s.food);

            group[groupNumber][indexArr[groupNumber]++] = s;
        }
    }

    // 리더 외 나머지 인원들 그룹에 투입 및 정렬(isPriority 기반)
    for (int g = 1 ; g <= 3 ; ++g){
        int gIndex = indexArr[g];

        for (int i = 0 ; i < gIndex - 1 ; ++i){
            for (int k = i + 1 ; k < gIndex ; ++k){
                STUDENT a = group[g][i];
                STUDENT b = group[g][k];

                if (isPriority(a, b) == false){ // 우선순위가 b가 더 높은 경우
                    group[g][i] = b;
                    group[g][k] = a;
                }
            }
        }
    }

    // 전파 수행
    for (int g = 1 ; g <= 3 ; ++g){
        int gIndex = indexArr[g];
        for (int i = 0 ; i < gIndex ; ++i){
            int gr = group[g][i].r;
            int gc = group[g][i].c;

            STUDENT spreader = student[gr][gc]; // 전파자
            int sr = spreader.r;
            int sc = spreader.c;
            student[sr][sc].believe = 1;

            int x = spreader.believe - 1; // 전파자의 간절함
            int d = spreader.believe % 4; 

            while (1){
                int nr = sr + D[d][0];
                int nc = sc + D[d][1];

                if (nr < 1 || nr >= N || nc < 1 || nc >= N || x == 0) continue;

                STUDENT next = student[nr][nc]; // 전파 대상

                // 전파 대상이 전파자와 신봉 음식이 완전히 동일한 경우 또는 방어상태의 학생인 경우, 바로 다음 전파자로 이동(좌표 갱신 필요)
                if (spreader.food == next.food || next.defense != 0){
                    // 다음 진행 (다음 전파자로 이동)
                    sr = nr;
                    sc = nc;

                    continue;
                }

                // 전파 성공/실패 유무와 무관하게, 대표자에게 전파가 시도된 학생은 방어상태
                student[next.r][next.c].defense = 1; // 방어상태 ON

                int y = next.believe;

                // 강한 전파
                if (x > y){
                    student[next.r][next.c].food = spreader.food;
                    student[next.r][next.c].believe++;

                    x -= (y + 1);
                    if (x < 0) x = 0; // 전파 종료되는 시점(while문 탈출)
                }

                // 약한 전파
                else{
                    student[next.r][next.c].food = mixFood(spreader.food, next.food);
                    x = 0;
                    student[next.r][next.c].believe += x;

                    break; // 전파는 더이상 진행되지 않고 종료
                }
                
                sr = nr;
                sc = nc;
            }
        }
    }

    // 방어 초기화
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            student[r][c].defense = 0;
        }
    }
}

void printAnswer(){
    int sum[MINTCHOCOMILK + 1] = { 0 };

    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            sum[student[r][c].food] += student[r][c].believe;
        }
    }

    int outputIndex[7] = {MINTCHOCOMILK, MINTCHOCO, MINTMILK, CHOCOMILK, MILK, CHOCO, MINT};

    for (int i = 0 ; i < 7 ; ++i){
        cout << sum[outputIndex[i]] << ' ';
    }
    cout << '\n';
}

void simulate(){
    for (int t = 0 ; t < T ; ++t){
        process_morning();
        process_lunch();
        process_dinner();
        printAnswer();
    }
}

int main(){ 
    fastio();
    input();
    simulate();
    return 0;
}