#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1234567

using namespace std;

int F, S, G, U, D, res; // F: 총 층수, S: 현위치, G: 목적층, U: U칸 위, D: D칸 아래

bool isFound = false;
bool visited[MAX];


void input(){
    cin >> F >> S >> G >> U >> D;
}

void BFS(){
    queue<pair<int, int>> myqueue; // 현위치, 버튼 누른 횟수
    myqueue.push({S, 0});
    visited[S] = true;

    while (!myqueue.empty()){
        int curr_floor = myqueue.front().first, curr_button_cnt = myqueue.front().second;

        myqueue.pop();

        if (curr_floor == G){
            isFound = true;
            res = curr_button_cnt;
            break;
        }

        // 위 버튼
        if (U > 0 && curr_floor + U <= F && !visited[curr_floor + U]){
            myqueue.push({curr_floor + U, curr_button_cnt + 1});
            visited[curr_floor + U] = true;
        }

        // 아래 버튼
        if (D > 0 && curr_floor - D >= 1 && !visited[curr_floor - D]){
            myqueue.push({curr_floor - D, curr_button_cnt + 1});
            visited[curr_floor - D] = true;
        }
    }

}

void solve(){
    BFS();

    if (!isFound){
        cout << "use the stairs";
        return;
    }

    cout << res;
}

int main(){
    fastio
    input();
    solve();
    return 0;
}