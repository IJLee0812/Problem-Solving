#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    priority_queue<int, vector<int>, cmp> pq;
    vector<int> v;

    int N, x; cin >> N;
    
    for (int i = 0 ; i < N ; ++i){
        cin >> x;

        if (x == 0){ // delete
            if (pq.empty()) v.push_back(0);
            else{ 
                v.push_back(pq.top());
                pq.pop();
            }
        }
        else pq.push(x); // add
    }

    for (int i = 0 ; i < v.size() ; ++i) cout << v[i] << '\n'; 
    
    return 0;
}
