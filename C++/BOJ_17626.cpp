#include <iostream>
#include <algorithm>
using namespace std;
int D[50001];

int main(){

    int n; cin >> n;
    for (int i = 1 ; i <= n ; ++i){
        D[i] = D[i-1] + 1;
        for (int j = 1 ; j * j <= i ; ++j){
            D[i] = min(D[i], D[i-j*j] + 1);
        }
    }
    cout << D[n]; 
    return 0;
}