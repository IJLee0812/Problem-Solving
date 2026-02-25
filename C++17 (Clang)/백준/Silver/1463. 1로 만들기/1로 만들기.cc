#include <iostream>
using namespace std;
int arr[1000005];
int main(){
    int n; cin >> n;
    for (int i = 2 ; i <= n ; ++i){
        arr[i] = arr[i-1] + 1;
        if (i % 2 == 0) arr[i] = min(arr[i/2]+1, arr[i]);
        if (i % 3 == 0) arr[i] = min(arr[i/3]+1, arr[i]);
    }
    cout << arr[n] << endl;
}