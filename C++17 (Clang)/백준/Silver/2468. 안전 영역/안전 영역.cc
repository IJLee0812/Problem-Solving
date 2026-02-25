#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

int N, maxHeight = 0, maxSafeArea = 0;
int area[MAX][MAX];
bool tempmap[MAX][MAX];
bool visited[MAX][MAX];

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Point {
    int x, y;
};

void inittempmap(int height) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            tempmap[i][j] = area[i][j] > height;
}

void bfs(int x, int y) {
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = curr.x + D[d][0];
            int ny = curr.y + D[d][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
                !visited[nx][ny] && tempmap[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int countSafeAreas() {
    int count = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!visited[i][j] && tempmap[i][j]) {
                bfs(i, j);
                count++;
            }
    return count;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> area[i][j];
            if (area[i][j] > maxHeight)
                maxHeight = area[i][j];
        }

    // 높이 0부터 maxHeight - 1까지 돌기 (0은 비가 아예 안 온 경우)
    for (int height = 0; height < maxHeight; ++height) {
        memset(tempmap, false, sizeof(tempmap));
        memset(visited, false, sizeof(visited));

        inittempmap(height);
        int safeArea = countSafeAreas();

        if (safeArea > maxSafeArea)
            maxSafeArea = safeArea;
    }

    cout << maxSafeArea << "\n";
    return 0;
}
