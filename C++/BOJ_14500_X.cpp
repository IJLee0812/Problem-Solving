#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// 19개의 테트로미노 형태를 정의
int tetromino[19][4][2] = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, // 일자형 가로
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, // 일자형 세로
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, // 정사각형
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}}, // ㄱ자형 1
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}}, // ㄱ자형 2
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}}, // ㄱ자형 3
    {{0, 2}, {1, 2}, {1, 1}, {1, 0}}, // ㄱ자형 4
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, // ㄱ자형 반대 1
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}}, // ㄱ자형 반대 2
    {{0, 0}, {1, 0}, {2, 0}, {2, -1}}, // ㄱ자형 반대 3
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, // ㄱ자형 반대 4
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}}, // Z형 1
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}}, // Z형 2
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}}, // Z형 반대 1
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, // Z형 반대 2
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}}, // T형 1
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}}, // T형 2
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}}, // T형 3
    {{0, 1}, {1, 0}, {1, 1}, {2, 1}}  // T형 4
};

int Map[501][501];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> Map[i][j];

    int res = 0;

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            for (int k = 0; k < 19; ++k){ 
                Point one = {i + tetromino[k][0][0], j + tetromino[k][0][1]};
                Point two = {i + tetromino[k][1][0], j + tetromino[k][1][1]};
                Point three = {i + tetromino[k][2][0], j + tetromino[k][2][1]};
                Point four = {i + tetromino[k][3][0], j + tetromino[k][3][1]};

                if (one.x >= 0 && two.x >= 0 && three.x >= 0 && four.x >= 0 && 
                    one.x < N && two.x < N && three.x < N && four.x < N && 
                    one.y >= 0 && two.y >= 0 && three.y >= 0 && four.y >= 0 && 
                    one.y < M && two.y < M && three.y < M && four.y < M){
                    int sum = 0;
                    sum += Map[one.x][one.y];
                    sum += Map[two.x][two.y];
                    sum += Map[three.x][three.y];
                    sum += Map[four.x][four.y];
                    res = max(sum, res);
                }
            }
        }
    }

    cout << res << '\n';
    return 0;
}