#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq1; // 최소 
priority_queue<int, vector<int>, less<int>> pq2; // 최대
unordered_map<int, int> cnt;

void initpq(){
    while(!pq1.empty()) pq1.pop();
    while(!pq2.empty()) pq2.pop();
}

void insert(int n){
    pq1.push(n); pq2.push(n);
    cnt[n]++;
}

void deletepq1(){
    if (!pq1.empty()){ 
        cnt[pq1.top()]--;
        pq1.pop();
    }
}

void deletepq2(){
    if (!pq2.empty()){ 
        cnt[pq2.top()]--;
        pq2.pop();
    }
}

void clearpqs(){
    while (!pq1.empty() && cnt[pq1.top()] == 0) pq1.pop();
    while (!pq2.empty() && cnt[pq2.top()] == 0) pq2.pop();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T, k, n; cin >> T;
    char op;

    while(T--){
        cin >> k;
        initpq();
        cnt.clear();

        for (int i = 0 ; i < k ; ++i){
            cin >> op >> n;
            if (op == 'I') insert(n);
            else{ 
                if (n == -1) deletepq1();
                else deletepq2();
                clearpqs();
            }
        }

        clearpqs();

        if (pq1.empty() || pq2.empty()) cout << "EMPTY\n";
        else cout << pq2.top() << ' ' << pq1.top() << '\n';
    }

    return 0;
}