#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

struct Node{
    char left, right;
};

map<char, Node> M;

void preOrder(char d){
    if (d == '.') return;
    cout << d;
    preOrder(M[d].left);
    preOrder(M[d].right);
}

void inOrder(char d){
    if (d == '.') return;
    inOrder(M[d].left);
    cout << d;
    inOrder(M[d].right);
}

void postOrder(char d){
    if (d == '.') return;
    postOrder(M[d].left);
    postOrder(M[d].right);
    cout << d;
}

int main(){
    int N; cin >> N;
    char data, left, right;
    for (int i = 0 ; i < N ; ++i){
        cin >> data >> left >> right;
        M[data].left = left;
        M[data].right = right;
    }
    preOrder('A'); cout << endl;
    inOrder('A'); cout << endl;
    postOrder('A'); cout << endl;
    return 0;
}   