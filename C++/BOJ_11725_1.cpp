#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int N, parentnum[MAX]; // 각 인덱스 노드의 부모 노드 번호 저장(인덱스 2부터 사용)

void solve(int root){ // BFS
    visited[root] = true;

    queue<int> q; q.push(root);

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for (auto child : graph[parent]){
            if (!visited[child]){
                visited[child] = true;
                parentnum[child] = parent;
                q.push(child);
            }
        }
    }

    for (int i = 2 ; i <= N ; ++i) cout << parentnum[i] << '\n';
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

    solve(1);

    return 0;
}
