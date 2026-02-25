#include <iostream>
#define MAX 100
using namespace std;
int A[MAX][MAX], B[MAX][MAX], res[MAX][MAX];
int main(){
    int n, m; cin >> n >> m;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
            cin >> A[i][j];  
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
            cin >> B[i][j];      
    for (int i = 0 ; i < n ; ++i){
        for (int j = 0 ; j < m ; ++j){
            res[i][j] = A[i][j] + B[i][j];
            cout << res[i][j] << ' ';   
        }
        cout << '\n';
    }
    return 0;
}