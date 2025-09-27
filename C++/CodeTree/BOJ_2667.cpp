// BFS 빈출유형(단지번호붙이기): BFS + Grouping 수행
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 26
using namespace std;

struct Point{
    int x, y;
};

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> groups;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}

// (input 한 줄이 문자열 형태임에 유의)
void input(){
    cin >> N;
    string line;
    for (int i = 0 ; i < N ; ++i){
        cin >> line;
        for (int j = 0 ; j < N ; ++j){
            map[i][j] = line[j] - '0';
        }
    }
}

int BFS(int x, int y){
    queue<Point> myqueue;
    myqueue.push({x, y});
    visited[x][y] = true;
    int house_count = 1;

    while (!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        
        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0];
            int ny = curr.y + D[i][1];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1 || visited[nx][ny] || !map[nx][ny]) continue;
            
            visited[nx][ny] = true;
            myqueue.push({nx, ny});
            house_count++;
        }
    }

    return house_count;
}

void simulate(){
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            if (!visited[i][j] && map[i][j]){
                groups.push_back(BFS(i, j));
            }
        }
    }
}

void printAnswer(){
    cout << groups.size() << '\n';

    sort(groups.begin(), groups.end());

    for (int g : groups){
        cout << g << '\n';
    }
}

int main(){
    fastio();
    input();
    simulate();
    printAnswer();
    return 0;
}