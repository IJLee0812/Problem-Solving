#include <bits/stdc++.h>
using namespace std;

int tri[501][501], dp[501][501], n;

int path(int x, int y){
    if (x == n - 1) return tri[x][y];

    int &r = dp[x][y]; // C++ 참조변수 사용 : 값을 복사하지 않기 때문에 메모리 사용량 및 실행 시간 절약. 일반 변수 사용 시, 시간 초과 발생.
    if (r != -1) return r;

    return r = max(path(x + 1, y), path(x + 1, y + 1)) + tri[x][y];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < i + 1 ; ++j)
            cin >> tri[i][j];
    
    memset(dp, -1, sizeof(dp));
    cout << path(0, 0);

    return 0;
}
