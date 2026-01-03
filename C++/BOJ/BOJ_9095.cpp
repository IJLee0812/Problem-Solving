#include <iostream>
#include <vector>
#include <cstring> // for memset

using namespace std;

int n;
int cache[12];

int recur(int num){
    if (num == 1) return 1;
    if (num == 2) return 2;
    if (num == 3) return 4;

    // 메모이제이션
    if (cache[num] != -1) return cache[num];

    return cache[num] = recur(num - 1) + recur(num - 2) + recur(num - 3);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, T; cin >> T;

    while (T--){
        cin >> N;

        memset(cache, -1, sizeof(cache));

        cout << recur(N) << '\n';
    }
}