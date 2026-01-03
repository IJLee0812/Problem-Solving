#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, x, ans = 5; cin >> N;

    while (N--){
        cin >> x;
        s.insert(x);
    }

    for (auto x : s){
        int cnt = 4;
        for (int i = 1 ; i < 5 ; ++i)
            if (s.count(x + i)) cnt--;
        ans = min(ans, cnt);
    }

    cout << ans;
}