#include <iostream>
using namespace std;

int cnt[201]; // -100 : 0, 0 : 100 100 : 200

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N, v, r; cin >> N;
    for (int i = 0 ; i < N ; ++i){
        cin >> v;
        cnt[v+100]++;
    }
    cin >> r;
    cout << cnt[r+100] << endl;
    return 0;
}