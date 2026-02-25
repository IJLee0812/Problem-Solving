#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int N, seq[MAX], D[MAX];
int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> seq[i];
    for (int i = 1; i <= N; ++i) {
        D[i] = 1; 
        for (int j = 1; j < i; ++j) {
            if (seq[i] > seq[j])
                D[i] = max(D[i], D[j] + 1);
        }
    }
    int MAXV = 0;
    for (int i = 1; i <= N; ++i)
        MAXV = max(MAXV, D[i]);
    cout << MAXV;
    return 0;
}
