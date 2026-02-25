// 1이면 단지가 있는 것 0이면 없는 것

#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 26
using namespace std;

struct Point{
    int row, col;
};

int N, Graph[MAX][MAX], D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, numhouse[MAX*MAX];

void DFS(int row, int col, int house){
    bool visited[MAX][MAX] = { false };
    stack<Point> mystack;
    mystack.push({row, col});
    Graph[row][col] = 0;
    int housecount = 0;
    while(!mystack.empty()){
        Point curr = mystack.top();
        mystack.pop();
        if (visited[curr.row][curr.col]) continue;
        visited[curr.row][curr.col] = true;
        Graph[curr.row][curr.col] = 0;
        housecount++;
        for (int i = 0 ; i < 4 ; ++i){
            int nr = curr.row + D[i][0];
            int nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
            if (visited[nr][nc]) continue;
            if (Graph[nr][nc] == 0) continue;
            mystack.push({nr, nc});
        }
    }
    numhouse[house] = housecount;
}

int main(){
    cin >> N;
    for (int i = 0 ; i < N ; ++i){
        string str; cin >> str;
        for (int j = 0 ; j < N ; ++j)
            Graph[i][j] = str[j] - '0';
    }
    int house = 0;
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            if (Graph[i][j] == 1){
                DFS(i, j, house);
                house++;
            }
        }
    }
    sort(numhouse, numhouse+house);
    cout << house << '\n';
    for (int i = 0 ; i < house ; ++i) cout << numhouse[i] << '\n';
    return 0;
}