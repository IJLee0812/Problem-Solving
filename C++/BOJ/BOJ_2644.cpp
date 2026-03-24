#include <iostream>
#include <queue>
#include <vector>
#define MAX 102
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, a, b, m, x, y; // a, b: 촌수 계산해야 하는 서로 다른 두 사람의 번호 

struct Node{
    int parent;
    vector<int> childs;
    int cnt = 0;
};

Node nodes[MAX];
bool visited[MAX];

void input(){
    cin >> n >> a >> b >> m;

    for (int i = 0 ; i < m ; ++i){
        cin >> x >> y;
        nodes[y].parent = x;
        nodes[x].childs.push_back(y);
    }
}

void solve(){
    queue<Node> myqueue;

    myqueue.push({nodes[a]}); // a 넣고 b 찾기
    visited[a] = true;

    while (!myqueue.empty()){
        Node curr = myqueue.front();
        myqueue.pop();

        if (curr.parent == b){
            cout << curr.cnt + 1;
            return;
        }

        for (auto c : curr.childs){
            if (c == b){
                cout << curr.cnt + 1;
                return;
            }

            if (!visited[c]){
                visited[c] = true;
                nodes[c].cnt = curr.cnt + 1;
                myqueue.push({nodes[c]});
            }
        }

        if (!visited[curr.parent]){
            visited[curr.parent] = true;
            nodes[curr.parent].cnt = curr.cnt + 1;
            myqueue.push({nodes[curr.parent]});
        }
        
    }

    // 친척 관계가 전혀 없을 때
    cout << "-1";
}

int main(){
    fastio
    input();
    solve();
    return 0;
}