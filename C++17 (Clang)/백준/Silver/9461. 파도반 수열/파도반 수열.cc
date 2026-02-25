#include <iostream>
using namespace std;
long long D[101];
int main(){
    D[0] = 1;
    D[1] = 1;
    D[2] = 1;
    int test_case; cin >> test_case;
    for (int i = 0 ; i < test_case ; ++i){
        int N; cin >> N;
        for (int j = 3 ; j < N ; ++j){
            D[j] = D[j-2] + D[j-3];
        }
        cout << D[N-1] << '\n';
    }
    return 0;
}