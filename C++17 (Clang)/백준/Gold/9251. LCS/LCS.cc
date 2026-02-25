#include <iostream>
#include <algorithm>
using namespace std;
int D[1001][1001];
int main(){
    string A, B;
    cin >> A >> B;
    int a = A.length(), b = B.length();
    for (int i = 1 ; i <= a ; ++i){
        for (int j = 1 ; j <= b ; ++j){
            if (A[i-1] == B[j-1])
                D[i][j] = D[i-1][j-1] + 1;
            else D[i][j] = max(D[i-1][j], D[i][j-1]);
        }
    }
    cout << D[a][b];
    return 0;
}