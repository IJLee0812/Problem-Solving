#include <iostream>
using namespace std;
int main(){
    int N; cin >> N;
    int cnt = 0;
    while (N >= 5){
        cnt += N / 5;
        N /= 5;
    }
    cout << cnt << '\n';
    return 0;
}