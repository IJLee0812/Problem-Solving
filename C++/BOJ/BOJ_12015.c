#include <stdio.h>
#define MAX 1000005

int N, A[MAX], L[MAX], L_len;

int lower_bound(int target){
    int l = 0, r = L_len - 1;

    while (l <= r){
        int m = (l + r) / 2;

        if (L[m] < target) l = m + 1;
        else r = m - 1;
    }

    // 크거나 같음 == l이 첫 인덱스
    return l;
}

int main(void){
    if (scanf("%d", &N) != 1) return 0;

    for (int i = 0 ; i < N ; ++i) scanf("%d", &A[i]);

    for (int i = 0 ; i < N ; ++i){
        if (L_len == 0 || L[L_len - 1] < A[i]) L[L_len++] = A[i];

        else{
            int pos = lower_bound(A[i]);
            L[pos] = A[i];
        }
    }

    printf("%d", L_len);

    return 0;
}