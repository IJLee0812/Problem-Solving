#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 202

using namespace std;

struct Virus{
    int v, x, y;
    
    bool operator<(const Virus& other) const{
        return v < other.v; 
    }
};

queue<Virus> myqueue;
vector<Virus> init_viruses; 

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N, K, S, X, Y;
int Graph[MAX][MAX];

void input(){
    cin >> N >> K;
    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            cin >> Graph[i][j];
            if (Graph[i][j]) init_viruses.push_back({Graph[i][j], i, j});
        }
    }
    cin >> S >> X >> Y;
}

void init(){
    sort(init_viruses.begin(), init_viruses.end());

    for (const auto& virus : init_viruses) myqueue.push(virus);
}

void diffuse(){
    queue<Virus> temp_queue;

    while (!myqueue.empty()){
        Virus curr = myqueue.front();
        myqueue.pop();

        for (int i = 0 ; i < 4 ; ++i){
            int nx = curr.x + D[i][0], ny = curr.y + D[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !Graph[nx][ny]){
                Graph[nx][ny] = curr.v;
                temp_queue.push({curr.v, nx, ny});
            }
        }
    }

    myqueue = temp_queue;
}

void simulate(){
    init();

    while (S--) diffuse();

    cout << Graph[X - 1][Y - 1] << '\n';
}

int main(){
    fastio
    input();
    simulate();
    return 0;
}