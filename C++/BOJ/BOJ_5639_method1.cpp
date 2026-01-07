#include <iostream>
using namespace std;

struct Node{
    int num;
    Node* left;
    Node* right;
    Node(int val) : num(val), left(nullptr), right(nullptr) {}
};
Node* root = nullptr;

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void insert(Node*& node, int n){ // using pointer's reference(*&)
    if (node == nullptr){
        node = new Node(n);
        return;
    }

    if (n < node->num) insert(node->left, n);
    else insert(node->right, n);
}

void input(){
    int n;
    while(cin >> n) insert(root, n);   
}

void postorder(Node* curr){
    // base case
    if (curr == nullptr) return;

    postorder(curr->left);
    postorder(curr->right);
    cout << curr->num << '\n';
}

int main(){
    fastio();
    input();
    postorder(root);
    return 0;
}