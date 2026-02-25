#include <bits/stdc++.h>
using namespace std;

int T, A, B;
bool visited[10000];

int D(int A) {
    return (A * 2) % 10000;
}

int S(int A) {
    return (A == 0) ? 9999 : A - 1;
}

int L(int A) {
    return (A % 1000) * 10 + A / 1000;
}

int R(int A) {
    return (A % 10) * 1000 + A / 10;
}

void bfs(int A, int B) {
    fill(visited, visited + 10000, false);
    queue<pair<int, string>> q;
    q.push({A, ""});
    visited[A] = true;

    while (!q.empty()) {
        int num = q.front().first;
        string cmd = q.front().second;
        q.pop();

        if (num == B) {
            cout << cmd << '\n';
            return;
        }

        int d = D(num);
        if (!visited[d]) {
            visited[d] = true;
            q.push({d, cmd + 'D'});
        }

        int s = S(num);
        if (!visited[s]) {
            visited[s] = true;
            q.push({s, cmd + 'S'});
        }

        int l = L(num);
        if (!visited[l]) {
            visited[l] = true;
            q.push({l, cmd + 'L'});
        }

        int r = R(num);
        if (!visited[r]) {
            visited[r] = true;
            q.push({r, cmd + 'R'});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> A >> B;
        bfs(A, B);
    }

    return 0;
}