#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int T, M, N, K, x, y; 

struct Point{
    int x, y;
};

int graph[MAX][MAX], cnt;

void DFS(int x, int y){
    stack<Point> mystack;
    mystack.push({x, y});

    while (!mystack.empty()){
        Point curr = mystack.top();
        mystack.pop();

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N){
                if (graph[nx][ny] == 1){
                    graph[nx][ny] = 0;
                    DFS(nx, ny);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while (T--){
        memset(graph, 0, sizeof(graph));
        cin >> M >> N >> K;
        
        for (int i = 0 ; i < K ; ++i){
            cin >> x >> y;
            graph[x][y] = 1;
        }

        for (int i = 0 ; i < M ; ++i){
            for (int j = 0 ; j < N ; ++j){
                if (graph[i][j] == 1){
                    cnt++;
                    DFS(i, j);
                }
            }
        }

        cout << cnt << '\n';
        cnt = 0;
    }

    return 0;
}
