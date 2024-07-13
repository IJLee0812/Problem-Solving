#include <bits/stdc++.h>
using namespace std;

struct Point{
    int z, x, y;
};

int D[6][3] = {{0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}, {-1, 0, 0}, {1, 0, 0}}; // 상, 하, 좌, 우, 위, 아래
int M, N, H, Chest[100][100][100], day = 0;

queue<Point> myqueue;

void BFS(){
    while (!myqueue.empty()){
        int currSize = myqueue.size(); // 각 레벨마다의 현 크기

        for (int q = 0 ; q < currSize ; q++){
            Point curr = myqueue.front();
            myqueue.pop();

            for (int i = 0 ; i < 6 ; ++i){
                int nz = curr.z + D[i][0], nx = curr.x + D[i][1], ny = curr.y + D[i][2];
                if (nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M && Chest[nz][nx][ny] == 0){
                    myqueue.push({nz, nx, ny});
                    Chest[nz][nx][ny] = 1;
                }
            }
        }

        day++; // loop 1번 순회 후 day +1 update
    }
    
    // update complete

    for (int i = 0 ; i < H ; ++i)
        for (int j = 0 ; j < N ; ++j)
            for (int k = 0 ; k < M ; ++k){
                if (Chest[i][j][k] == 0){
                    cout << "-1\n"; // 불가능
                    return;
                }
            }
    
    cout << day - 1 << '\n';
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N >> H;

    for (int i = 0 ; i < H ; ++i)
        for (int j = 0 ; j < N ; ++j)
            for (int k = 0 ; k < M ; ++k){
                cin >> Chest[i][j][k];
                if (Chest[i][j][k] == 1) myqueue.push({i, j, k});
            }

    BFS();
    return 0;
}