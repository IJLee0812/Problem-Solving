#include <iostream>
#define MAX 1001
using namespace std;
int cost[MAX][4], arr[MAX][4];
int main(){
    int i, j, n; cin >> n;
    for (i = 1 ; i <= n ; ++i)
        for (j = 1 ; j <= 3 ; ++j)
            cin >> cost[i][j];
    arr[1][1] = cost[1][1];
    arr[1][2] = cost[1][2];
    arr[1][3] = cost[1][3];
    for (i = 2 ; i <= n ; ++i){
        arr[i][1] = min(arr[i-1][2], arr[i-1][3]) + cost[i][1];
        arr[i][2] = min(arr[i-1][1], arr[i-1][3]) + cost[i][2];
        arr[i][3] = min(arr[i-1][1], arr[i-1][2]) + cost[i][3];
    }
    int res = arr[n][1]; 
    for (i = 2 ; i <= 3 ; ++i){
        if (res > arr[n][i]) res = arr[n][i];
    }
    cout << res << endl;
}