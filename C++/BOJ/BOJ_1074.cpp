#include <bits/stdc++.h>
using namespace std;

int N, r, c, ans;

void Z(int y, int x, int size){
    if (y == r && x == c){
        cout << ans;
        return;
    }

    // 만약 r, c가 현재 사분면에 존재하는 경우(처음에는 무조건 배열에 존재함에 유의)
    if (r < y + size && r >= y && c < x + size && c >= x){  
        // 1사분면 탐색
        Z(y, x, size / 2);

        // 2사분면 탐색
        Z(y, x + size / 2, size / 2);

        // 3사분면 탐색
        Z(y + size / 2, x, size / 2);

        // 4사분면 탐색
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else ans += size * size; // 2^N * 2^N
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    
    cin >> N >> r >> c;

    Z(0, 0, (1 << N));

    return 0;
}
