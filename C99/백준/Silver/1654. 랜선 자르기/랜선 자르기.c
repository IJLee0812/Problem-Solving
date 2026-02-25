#include <stdio.h>
int K, N;
long long lan[10001] = {0, };
long long binsearch(long long s, long long e){
    while (s <= e){
        int tot = 0;
        long long m = (s + e) / 2;
        for (int i = 0; i <= K; i++){
            tot += lan[i] / m;
        }
        if (tot >= N) s = m + 1;
        else e = m - 1;
    }
    return e;
}
int main(void){
    long long max = 0;    
    scanf("%d %d", &K, &N); 
    for(int i=0; i<K; i++){
        scanf("%lld", &lan[i]);
        if (max < lan[i]) max = lan[i];
    }
    printf("%lld\n", binsearch(1, max));
    return 0;
}