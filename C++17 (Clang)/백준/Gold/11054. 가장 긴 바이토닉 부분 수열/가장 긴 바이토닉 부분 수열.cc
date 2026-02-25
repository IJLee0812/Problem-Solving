#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int N, seq[MAX], DL[MAX], DR[MAX], DS[MAX];
int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> seq[i];
    for (int i = 1; i <= N; ++i) {
        DL[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (seq[i] > seq[j]) {
                DL[i] = max(DL[i], DL[j] + 1);
            }
        }
    }
    for (int i = N; i >= 1; --i) {
        DR[i] = 1;
        for (int j = N; j > i; --j) {
            if (seq[i] > seq[j]) {
                DR[i] = max(DR[i], DR[j] + 1);
            }
        }
    }
    int MAXV = 0;
    for (int i = 1; i <= N; ++i) {
        DS[i] = DL[i] + DR[i] - 1; // 바이토닉 부분 수열 길이 (1 중복 제거)
        if (MAXV < DS[i]) MAXV = DS[i];
    }
    cout << MAXV << '\n';
    return 0;
}
