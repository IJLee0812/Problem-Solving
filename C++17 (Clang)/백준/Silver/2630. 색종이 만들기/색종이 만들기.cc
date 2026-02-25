#include <iostream>
#define MAX 129
using namespace std;
int N, white = 0, blue = 0, P[MAX][MAX];
void f(int x, int y, int range){
    int v = P[x][y];
    bool iscut = false;
    for (int i = x ; i < x + range ; ++i){
        for (int j = y ; j < y + range ; ++j){
            if (P[i][j] != v){
                iscut = true;
                break;
            }
        }
    }
    if (iscut){
        f(x, y, range / 2);
        f(x, y + range / 2, range / 2);
        f(x + range / 2, y, range / 2);
        f(x + range / 2, y + range / 2, range / 2);
    }
    else{
        if (v == 1) blue++;
        else white++;
    }
}
int main(){
    cin >> N;
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            cin >> P[i][j];
    f(0, 0, N);
    cout << white << '\n' << blue << '\n';
    return 0;
}