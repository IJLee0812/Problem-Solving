#include <iostream>
using namespace std;
int D[100001];
int main(){
    int N; cin >> N;
    for (int i = 1 ; i <= N ; ++i){
        D[i] = i;
        for (int j = 1 ; j * j <= i ; ++j)
            D[i] = min(D[i], D[i - j * j] + 1);
    }
    cout << D[N];
}