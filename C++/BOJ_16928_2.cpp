#include <bits/stdc++.h>
using namespace std;

struct Point{
    int location, count;
};

int d[101];
bool visited[101];

void BFS(){
    queue<Point> q;
    q.push({1, 0});

    while(!q.empty()){
        Point curr = q.front();
        q.pop();

        for (int i = 1 ; i <= 6 ; ++i){
            int new_location = curr.location + i;

            if (new_location == 100){
                cout << curr.count + 1;
                return;
            }

            if (!visited[new_location]){
                new_location = d[new_location];
                if (new_location > 100 || new_location < 0) continue;
                q.push({new_location, curr.count + 1});
                visited[new_location] = true;
            }

        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, x, y;

    cin >> N >> M;

    for (int i = 1 ; i <= 101 ; ++i) d[i] = i;

    for (int i = 0 ; i < N + M ; ++i){
        cin >> x >> y;
        d[x] = y;
    }

    BFS();

    return 0;
}
