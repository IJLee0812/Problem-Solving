#include <bits/stdc++.h>
using namespace std;

int fruitUse[9];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, fruit, res = 0; cin >> N;
    queue<int> fruits;
    
    for (int i = 0 ; i < N ; ++i){ 
        cin >> fruit;
        fruits.push(fruit);

        if (fruitUse[fruit - 1]++ == 0) res++;

        while (res > 2){ // 과일 하나가 들어올 때마다 검사해서 res 값을 계속 갱신해주는 과정이 중요함
            fruit = fruits.front();
            fruits.pop();
            if (--fruitUse[fruit - 1] == 0) res--;
        }

        res = max(res, static_cast<int>(fruits.size())); // 그냥 fruits.size()로 하면 오류. static casting 과정 필요
    }
    cout << res << '\n';
    return 0;
}
