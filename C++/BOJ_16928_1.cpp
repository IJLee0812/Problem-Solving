#include <bits/stdc++.h>
using namespace std;

int b[101], n[101];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 1 ; i <= 100 ; ++i){ 
        n[i] = i;
        b[i] = -1;
    }

    int N, M, x, y; // 사다리든, 뱀이든 둘 다 이동하기 때문에 굳이 구분안함

    cin >> N >> M;

    for (int i = 0 ; i < N + M ; ++i){
        cin >> x >> y;
        n[x] = y;
    }

    b[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()){
        int x = q.front();
        q.pop();

        for (int i = 1 ; i <= 6 ; ++i){
            int y = x + i;
            if (y > 100) continue;
            y = n[y]; // y가 뱀이나 사다리면 이동해야 함
            if (b[y] == -1){
                b[y] = b[x] + 1;
                q.push(y);
            }
        }
    }

    cout << b[100];

    return 0;
}
