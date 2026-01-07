#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void postorder(int start, int end){
    // Base Case
    if (start > end) return;

    if (start == end){
        cout << tree[start] << '\n';
        return;
    }

    int root = tree[start];
    int idx = start + 1;

    while (idx <= end){
        if (tree[idx] > root) break;
        idx++;
    }

    postorder(start + 1, idx - 1);

    postorder(idx, end);

    cout << root << '\n';
}

int main(){
    fastio();
    int n;
    while (cin >> n) tree.push_back(n);

    if (!tree.empty()) postorder(0, tree.size() - 1); // end idx: size - 1
    return 0;
}