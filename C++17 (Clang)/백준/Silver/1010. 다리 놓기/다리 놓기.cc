#include <iostream>
using namespace std;
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_case, N, M;
    cin >> test_case;
    for (int i = 0 ; i < test_case ; ++i){
        int answer = 1, temp = 1;
        cin >> N >> M;
        for(int j = M; j > M - N; j--) {
            answer *= j;
            answer /= temp++;
        }
        cout << answer << endl;
    }
}