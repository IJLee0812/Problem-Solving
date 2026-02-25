#include <bits/stdc++.h>
using namespace std;
int D[6][3] = {{0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}, {-1, 0, 0}, {1, 0, 0}}, M, N, H, day = 0; // 상, 하, 좌, 우, 위(z축), 아래(z축)
int Map[100][100][100];
struct Point{
    int z, x, y;
};
queue<Point> myqueue;
void BFS(){
    while(!myqueue.empty()){
        int size = myqueue.size();
        for (int i = 0 ; i < size ; ++i){
            Point curr = myqueue.front();
            myqueue.pop();
            for (int j = 0 ; j < 6 ; ++j){
                int nz = curr.z + D[j][0], nx = curr.x + D[j][1], ny = curr.y + D[j][2];
                if (nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M && Map[nz][nx][ny] == 0){
                    myqueue.push({nz, nx, ny});
                    Map[nz][nx][ny] = 1;
                }
            }
        } 
        day++;
    }
    for (int i = 0 ; i < H ; ++i)
        for (int j = 0 ; j < N ; ++j)
            for (int k = 0 ; k < M ; ++k)
                if (Map[i][j][k] == 0){
                    cout << "-1\n";
                    return;
                }
    cout << day - 1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M >> N >> H;
    for (int i = 0 ; i < H ; ++i)
        for (int j = 0 ; j < N ; ++j)
            for (int k = 0 ; k < M ; ++k)
                cin >> Map[i][j][k];
    for (int i = 0 ; i < H ; ++i)
        for (int j = 0 ; j < N ; ++j)
            for (int k = 0 ; k < M ; ++k)
                if (Map[i][j][k] == 1)
                    myqueue.push({i, j, k});
    BFS();
    return 0;
}
