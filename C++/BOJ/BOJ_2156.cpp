#include <iostream>
#include <algorithm>

using namespace std;

int grape[10001], D[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;

    for (int i = 1 ; i <= N ; ++i)
        cin >> grape[i];
    
    D[0] = 0;
    D[1] = grape[1];
    D[2] = grape[1] + grape[2];

    for (int i = 3 ; i <= N ; ++i)
        D[i] = max({D[i - 3] + grape[i - 1] + grape[i], D[i - 2] + grape[i], D[i - 1]});
    
    cout << D[N];

    return 0;
}
