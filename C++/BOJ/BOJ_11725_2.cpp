#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int N, parentnum[MAX];

void solve(int parent){ // DFS
    for (auto child : graph[parent]){
        if (!visited[child]){
            visited[child] = true;
            parentnum[child] = parent;
            solve(child);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    int n1, n2;

    for (int i = 0 ; i < N - 1 ; ++i){
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    visited[1] = true;
    solve(1);    

    for (int i = 2 ; i <= N ; ++i) cout << parentnum[i] << '\n';
    return 0;
}
