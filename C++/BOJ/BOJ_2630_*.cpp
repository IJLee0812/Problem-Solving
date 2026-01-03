#include <iostream>
using namespace std;
#define MAX 129
#define endl '\n'
int N, Paper[MAX][MAX], blue = 0, white = 0;

void f(int x, int y, int k){

    int val = Paper[x][y];
    bool isCut = false;
    for (int i = x ; i < x + k ; ++i){
        for (int j = y ; j < y + k ; ++j){
            if (Paper[i][j] != val)
                isCut = true;
                break;
        }
    }
    if (isCut){
        f(x, y, k/2); f(x, y+k/2, k/2);
        f(x + k/2, y, k/2); f(x + k/2, y + k/2, k/2);
    }
    else{
        if (val == 0) white++;
        else blue++;
    }
}

int main(){

    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            cin >> Paper[i][j];

    f(0, 0, N);
    cout << white << endl << blue << endl;
    return 0;
}