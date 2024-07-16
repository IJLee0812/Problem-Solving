#include <bits/stdc++.h>
using namespace std;

int fruitUse[9];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, fruit, res = 0, cnt = 0; cin >> N;
    queue<int> q;

    while(N--){
        cin >> fruit;
        q.push(fruit);

        if (fruitUse[fruit - 1]++ == 0)
            cnt++;
        
        while (cnt > 2){
            fruit = q.front();
            q.pop();
            if (--fruitUse[fruit - 1] == 0) cnt--;
        }

        res = max(res, static_cast<int>(q.size()));
    }

    cout << res << '\n';
    return 0;
}
