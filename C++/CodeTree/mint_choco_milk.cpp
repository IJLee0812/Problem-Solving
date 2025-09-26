#include <stdio.h>
#define MAX 51

// (효율화 전)
// #define TMINT_CHOKO_MILK (1)
// #define TMINT_CHOKO (2)
// #define TMINT_MILK (3)
// #define CHOKO_MILK (4)
// #define MILK (5)
// #define CHOKO (6)
// #define TMINT (7)

// (효율화 후: bitwise or 사용한 간편한 음식 추가)
#define TMINT_CHOKO_MILK (111)
#define TMINT_CHOKO (1 + 10)
#define TMINT_MILK (1 + 100)
#define CHOKO_MILK (100 + 10)
#define MILK (100)
#define CHOKO (10)
#define TMINT (1)

#define UP (0)
#define DOWN (1)
#define LEFT (2)
#define RIGHT (3)

int TestCase;
int N, T;
char F[MAX][MAX]; // 신봉하는 음식 저장 배열
int B[MAX][MAX];  // 신앙심(정수) 저장 배열

struct STUDENT{
    int food;       // 신봉하는 음식
    int believe;    // 신앙심
    bool isLeader;  // 대표자
    int defense;    // 방어 여부

    // 대표자 선정을 위한 값(좌표기준)
    int row;
    int col;
};

// 구조체배열(input 후단에서 추가매핑)
STUDENT student[MAX][MAX];
STUDENT candidates[MAX][MAX]; // 후보자 선정을 위한 상태관리 배열
int ccnt; // candidates 배열 전용 인덱스

// 전파 (세 그룹 순서대로 진행) 그룹 단위 저장 배열
STUDENT group[4][MAX * MAX];
int index[4];

struct RC{
    int r;
    int c;
};

RC queue[MAX * MAX];
bool visit[MAX][MAX];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void input(){
    scanf("%d %d", &N, &T);

    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            scanf("%c", &F[r][c]);
        }
    }

    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            scanf("%d", &B[r][c]);
        }
    }


    // 구조체에 재매핑
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            student[r][c].believe = B[r][c];
            student[r][c].isLeader = false;     // init
            student[r][c].defense = 0;          // init
            student[r][c].row = r;
            student[r][c].col = c;

            if (F[r][c] == 'T') student[r][c].food = TMINT;
            else if (F[r][c] == 'M') student[r][c].food = MILK;
            else student[r][c].food = CHOKO;

        }
    }
}


// 디버깅용 함수(그룹 확인)
void printGroup(){
    for (int g = 1 ; g <= 3 ; ++g){
        int gIndex = index[g];
        printf("group %d ", g);

        for (int i = 0 ; i < gIndex ; ++i){
            printf("(%d, %d) ", group[g][i].row, group[g][i].col);
        }

        putchar('\n');
    }
}


// 요구사항 구현(아침, 점심, 저녁)
void process_morning(){
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            student[r][c].believe++;
        }
    }
}


bool isPriority(STUDENT a, STUDENT b){
    if (a.believe != b.believe) return a.believe > b.believe; // 기준 1
    if (a.row != b.row) return a.row < b.row;                 // 기준 2
    return a.col < b.col;                                     // 기준 3
}


// 점심 번호붙이기 BFS
void BFS(int r, int c){
    int rp = 0, wp = 0;

    queue[wp].r = r;
    queue[wp++].c = c; // 바로 1 증가

    visit[r][c] = true;

    ccnt = 0;
    candidates[ccnt++] = student[r][c];

    while (rp < wp){
        RC out = queue[rp++];

        for (int i = 0 ; i < 4 ; ++i){
            int nr, nc;
            nr = out.r + dr[i];
            nc = out.c + dr[c];

            if (nr < 1 || nc < 1 || nr > N || nc > N) continue; // 범위초과 미고려

            if (visit[nr][nc] == true) continue;                // 기 방문지점 미고려

            if (student[out.r][out.c].food != student[nr][nc].food) continue;

            queue[wp].r = nr;
            queue[rp].c = nc;

            visit[nr][nc] = true;

            candidates[ccnt++] = student[nr][nc];
        }
    }

    // 그룹 리더 초기화
    STUDENT leader = { 0 };

    // 우선순위 기준에 따른 리더 부여
    for (int i = 0 ; i < ccnt ; ++i){
        if (isPriority(candidates[i], leader) == true){
            leader = candidates[i];
        }
    }

    // 구조체에 리더 정보 반영
    student[leader.row][leader.col].isLeader = true;
    // 그룹원 수 - 1만큼 신앙심 추가
    student[leader.row][leader.col].believe += (ccnt - 1);


    // (중요) 리더 말고 나머지 그룹원들은 신앙심 1씩 감소
    for (int i = 0 ; i < ccnt ; ++i){
        STUDENT c = candidates[i];

        if (c.row == leader.row && c.col == leader.col) continue;

        student[c.row][c.col].believe--;
    }
}


// 점심 요구사항 반영 - 번호붙이기 BFS
void process_lunch(){
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            visit[r][c] = false;
            student[r][c].isLeader = false; // 리더 정보 초기화
        }
    }

    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            if (visit[r][c] == true) continue;

            BFS(r, c);
        }
    }
}


// 그룹 번호 getter
int getGroupNumber(int food){
    if (food == TMINT_CHOKO_MILK) return 3;
    if (food == TMINT || food == CHOKO || food = MILK) return 1;
    return 2;
}


// 음식을 합치는 함수 (bitwise or 이용하여 간편하게 구현)
int mixFood(int sFood, int nFood){ // s == spreader, n == new(student)
    return sFood | nFood;
}


// 저녁 요구사항 반영
void process_dinner(){
    // init: 그룹 인덱스 초기화
    for (int g = 1 ; g <= 3 ; ++g) index[g] = 0;

    // 그룹 별 분리
    for (int r = 1 ; r <= N ; ++r){
        for (int c = 1 ; c <= N ; ++c){
            STUDENT s = student[r][c];

            if (s.isLeader == false) continue; // 리더 아닌 경우 무시

            // 리더인 학생의 음식을 통해 그룹 찾기
            int groupNumber = getGroupNumber(s.food);

            group[groupNumber][index[groupNumber]++] = s;
        }
    }

    // 그룹 내 정렬
    for (int g = 1 ; g <= 3 ; ++g){
        int gIndex = index[g];

        for (int i = 0 ; i < gIndex - 1 ; ++i){
            for (int k = i + 1 ; k < gIndex ; ++k){
                STUDENT a = group[g][i], b = group[g][k];

                if (isPriority(a, b) == false){ // swap trigger
                    group[g][i] = b;
                    group[g][k] = a;
                }
            }
        }
    }

    // 디버깅
    // printGroup() 

    // 전파 시작
    for (int g = 1 ; g <= 3 ; ++g){
        int gIndex = index[g];
        for (int i = 0 ; i < gIndex ; ++i){
            int gr, gc;

            gr = group[g][i].row;
            gc = group[g][i].col;

            // 전파자 생성
            STUDENT spreader = student[gr][gc];


            // (놓치는 것 주의) 방어 상태에서는, 대표자가 되어도 전파하지 않음
            if (spreader.defense != 0) continue;


            int sr = spreader.row, sc = spreader.col;

            // 원본의 신앙심을 1로 변경
            student[sr][sc].believe = 1;

            // 간절함 x = B - 1
            int x = spreader.believe - 1;

            // 전파자의 이동 방향 (mod 4)
            int dir = spreader.believe % 4;

            // 전파자 실제 이동 로직(simulation)
            while (1){
                int nr = sr + dr[dir], nc = sc + dc[dir];

                // 격자 밖으로 나가거나 || 간절함이 0이 되면 전파 종료
                if (nr < 1 || nr > N || nc < 1 || nc > N || x == 0) continue;

                // 전파 대상을 찾았음의 시점
                STUDENT next = student[nr][nc];

                // 전파 대상이 전파자와 신봉 음식이 완전히 동일한 경우 전파 종료(좌표 갱신 필요)
                // 다른 대표자가 전파를 시도하더라도, 같은 음식처럼 처리
                if (next.food = spreader.food || next.defense != 0){
                    sr = nr;
                    sc = nc;

                    continue;
                }

                // 전파 성공/실패 유무와 상관없이, 대표자에게 전파가 시도된 학생은 방어 상태
                student[next.row][next.col].defense = 1; // 



                // 전파 대상이 전파자와 신봉 음식이 다른 경우, 전파 시도
                int y = next.believe;
                    // 강한 전파 성공 시
                if (x > y){
                    x -= (y + 1); // 간절함 삭감
                    if (x < 0) x = 0; // 0이 된다면 전파진행 종료

                    student[next.row][next.col].believe++;
                    student[next.row][next.col].food = spreader.food;
                }
                    // 약한 전파 성공 시
                else{
                    student[next.row][next.col].believe += x;
                    student[next.row][next.col].food = mixFood(spreader.food, next.food); // 전파자의 음식과 합치는 로직

                    x = 0; // 간절함은 0

                    break;
                }

                sr = nr;
                sc = nc;

            }


        }
    }

    for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			student[r][c].defense = 0;

}


void printAnswer()
{
	int sum[TMINT_CHOKO_MILK + 1] = { 0 };

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			sum[student[r][c].food] += student[r][c].believe;

	int outputIndex[7]
		= { TMINT_CHOKO_MILK, TMINT_CHOKO, TMINT_MILK, CHOKO_MILK, MILK, CHOKO, TMINT };

	for (int i = 0; i < 7; i++)
		printf("%d ", sum[outputIndex[i]]);
	putchar('\n');
}


// 하루 시뮬레이션
void simulate(){
    for (int t = 0 ; t < T ; ++t){
        process_morning();
        process_lunch();
        process_dinner();
        printAnswer();
    }
}


int main(){
    input();
    simulate();
    return 0;
}