#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    deque<int> dq; dq.push_back(N);

    for (int i = N - 1 ; i >= 1 ; --i){
        dq.push_front(i);
        for (int j = 0 ; j < i ; ++j){
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }

    for (auto elem : dq) cout << elem << ' ';

    return 0;
}