#include <bits/stdc++.h>
using namespace std;

/*

    res - 1 = (종류1 + 1) x (종류2 + 1) x ... - 1(알몸)

*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T, n, res; cin >> T;
    string tmp, item;

    for (int i = 0 ; i < T ; ++i){
        cin >> n;
        map<string, int> fashion;
        for (int j = 0 ; j < n ; ++j){
            cin >> tmp >> item;
            fashion[item]++;
        }
        res = 1;

        for (auto x : fashion) res *= x.second + 1; // auto로 간편하게 map의 key / value 처리가능
        cout << res - 1 << '\n'; // 알몸이 아니어야 하므로 -1
    }

    return 0;
}
