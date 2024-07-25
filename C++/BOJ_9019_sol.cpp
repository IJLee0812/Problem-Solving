#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int T, A, B;
bool visited[MAX];

int D(int A){
    return (A * 2) % 10000; // 10000 안 넘어도 % 10000 하면 그대로 출력됨
}

int S(int A){
    return (A == 0) ? 9999 : A - 1; // ? 참인 경우 : 거짓인 경우;
}

// 1234 -> 2341 or 1000 -> 1 ( or ...)
int L(int A){
    return (A % 1000) * 10 + (A / 1000);
}

// 1234 -> 4123 or 1 -> 1000 ( or ...)
int R(int A){
    return (A % 10) * 1000 + (A / 10);
}

void BFS(int A, int B){
    fill(visited, visited + MAX, false);
    
    queue<pair<int, string>> q;
    q.push({A, ""}); // == q.push(make_pair(A, ""));
    visited[A] = true; // 0 ~ 10000

    while (!q.empty()){
        int num = q.front().first; // 숫자
        string cmd = q.front().second; // 커맨드(D, S, L, R)
        q.pop();

        if (num == B){ // BFS를 사용함으로써, 해당 문단에서 최솟값 탐색이 가능해짐. DFS는 최단경로를 보장하지 않는다. 목표 상태를 찾더라도, 그 경로가 최단 경로라는 보장이 없다.
            cout << cmd << '\n';
            break;
        }

        int d = D(num);
        if (!visited[d]){
            visited[d] = true;
            q.push({d, cmd + 'D'});
        }

        int s = S(num);
        if (!visited[s]){
            visited[s] = true;
            q.push({s, cmd + 'S'});
        }

        int l = L(num);
        if (!visited[l]){
            visited[l] = true;
            q.push({l, cmd + 'L'});
        }

        int r = R(num);
        if (!visited[r]){
            visited[r] = true;
            q.push({r, cmd + 'R'});
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while (T--){
        cin >> A >> B;
        BFS(A, B);
    }

    return 0;
}
