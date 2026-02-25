#include <iostream>
using namespace std;
int stair[303], arr[303], sum;
int main(){
    int i, n; cin >> n;
    for (i = 1 ; i <= n ; ++i){
        cin >> stair[i];
        sum += stair[i];
    }
    if (n <= 2){
        cout << sum;
        return 0;
    }
    for (i = 1 ; i <= 3 ; ++i)
        arr[i] = stair[i];
    for (i = 4 ; i <= n-1 ; ++i)
        arr[i] = min(arr[i-2] + stair[i], arr[i-3] + stair[i]);
    cout << sum - min(arr[n-1], arr[n-2]);
}