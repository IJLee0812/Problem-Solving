#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T, k, n; cin >> T;
    char op;

    while (T--){
        cin >> k;
        multiset<int> ms;

        for (int i = 0 ; i < k ; ++i){
            cin >> op >> n;
            if (op == 'I') ms.insert(n);
            else{ // (op == 'D')
                if (!ms.empty() && n == -1) ms.erase(ms.begin());
                else if (!ms.empty() && n == 1){
                    auto iter = ms.end(); iter--;
                    ms.erase(iter);
                }
            }
        }

        if (ms.empty()) cout << "EMPTY\n";
        else{
            auto iter = ms.end(); iter--;
            cout << *iter << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}
