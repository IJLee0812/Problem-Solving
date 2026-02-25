#include <bits/stdc++.h>
using namespace std;

int M, N, x, y, T;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    for (int i = 0 ; i < T ; ++i){
        cin >> M >> N >> x >> y;

        int rx, ry;

        if (x > y){
            rx = x - y + 1;
            ry = 1;
        }
        else{
            rx = 1;
            ry = y - x + 1;
        }

        int cnt = 1, nx = 1, ny = 1;
        bool stop = false;

        while(!stop){
            if (nx == rx && ny == ry){
                cnt += x - rx;
                nx = x;
                ny = y;
                stop = true;
            }
            else if (M - nx < N - ny){
                ny += M - nx + 1;
                cnt += M - nx + 1;
                nx = 1;
            }
            else if (M - nx > N - ny){
                nx += N - ny + 1;
                cnt += N - ny + 1;
                ny = 1;
            }
            else{
                cnt += N - ny;
                nx = M;
                ny = N;
                stop = true;
            }
        }

        if (nx == x && ny == y) cout << cnt << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
