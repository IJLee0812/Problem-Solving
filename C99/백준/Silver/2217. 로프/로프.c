#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void * b){
        return *(int *)b - *(int *)a;
}
int maxf(int a, int b){
        return a > b ? a : b;
}
int main() {
        int N; int i;
        scanf("%d", &N);
        int *rope = (int *)malloc(N * sizeof(int));
        for (i = 0; i < N; i++) {
                scanf("%d", &rope[i]);
        }
        qsort(rope, N, sizeof(int), comp);
        int max = 0;
        for (i = 0; i < N; i++) 
                max = maxf(max, rope[i] * (i+1));
        printf("%d", max);
        return 0;
}