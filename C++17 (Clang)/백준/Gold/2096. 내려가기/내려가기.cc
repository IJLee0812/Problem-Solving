#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100002

using namespace std;

int N;

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void solve(){
    cin >> N;

    int minmemo[3], maxmemo[3], input[3];
    cin >> input[0] >> input[1] >> input[2];
    minmemo[0] = maxmemo[0] = input[0]; 
    minmemo[1] = maxmemo[1] = input[1]; 
    minmemo[2] = maxmemo[2] = input[2];

    for (int i = 1 ; i < N ; ++i){
        cin >> input[0] >> input[1] >> input[2];

        // 덮어쓰기 전에, 이전 줄(윗줄) 값을 임시 변수에 저장해야 함!
        // (계산 도중에 memo 값이 바뀌면, 같은 줄의 다른 값 계산 때 꼬이기 때문)
        int prevmin0 = minmemo[0], prevmin1 = minmemo[1], prevmin2 = minmemo[2];
        int prevmax0 = maxmemo[0], prevmax1 = maxmemo[1], prevmax2 = maxmemo[2];

        minmemo[0] = min(prevmin0, prevmin1) + input[0];
        maxmemo[0] = max(prevmax0, prevmax1) + input[0];

        minmemo[1] = min({prevmin0, prevmin1, prevmin2}) + input[1];
        maxmemo[1] = max({prevmax0, prevmax1, prevmax2}) + input[1];

        minmemo[2] = min(prevmin1, prevmin2) + input[2];
        maxmemo[2] = max(prevmax1, prevmax2) + input[2];
    }

    int maxScore = max({maxmemo[0], maxmemo[1], maxmemo[2]});
    int minScore = min({minmemo[0], minmemo[1], minmemo[2]});

    cout << maxScore << " " << minScore;
}

int main(){
    fastio();

    solve();

    return 0;
}