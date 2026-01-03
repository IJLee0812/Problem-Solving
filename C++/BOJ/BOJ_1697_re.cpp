#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int N, K;
bool visited[MAX];

void BFS(){
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;

    while(!q.empty()){
        int currLoc = q.front().first;
        int currSec = q.front().second;
        q.pop();

        if (currLoc == K){
            cout << currSec << '\n';
            break;
        }

        int back = currLoc - 1, front = currLoc + 1, warp = currLoc * 2;

        if (back >= 0 && !visited[back]){
            visited[back] = true;
            q.push({back, currSec + 1});
        }
        
        if (front <= MAX && !visited[front]){
            visited[front] = true;
            q.push({front, currSec + 1});
        }

        if (warp <= MAX && !visited[warp]){
            visited[warp] = true;
            q.push({warp, currSec + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // fill(visited, visited + MAX, false);
    cin >> N >> K;

    BFS();

    return 0;
}
