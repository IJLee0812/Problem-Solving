#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int parent[MAX], N, M, op, a, b;

int find(int x){
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x > y) parent[x] = y; // ex) x = 3, y = 2일 때 2 <- 3
    else parent[y] = x; // ex) x = 3, y = 4일 때 3 <- 4
}

void isUnion(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0 ; i <= N ; ++i) parent[i] = i;

    while (M--){
        cin >> op >> a >> b;
        if (op == 0) merge(a, b);
        else isUnion(a, b);
    }

    return 0;
}
