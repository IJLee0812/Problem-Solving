#include <iostream>
#define MAX 1000100
using namespace std;
long long tree[MAX];
long long l, r, m, res;
int main(){
    int N, M; cin >> N >> M;
    long long sum;
    for (int i = 0 ; i < N ; ++i){
        cin >> tree[i];
        if (r < tree[i])
            r = tree[i];
    }
    while (l <= r){
        m = (l + r) / 2;
        sum = 0;
        for (int i = 0 ; i < N ; ++i){
            if (tree[i] > m)
                sum += (tree[i] - m);
        }
        if (sum >= M && m > res)
            res = m;
        if (res < m){ 
            r = m - 1;
        }
        else{ 
            l = m + 1;
        }
    }
    cout << res << endl;
}