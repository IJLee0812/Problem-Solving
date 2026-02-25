#include <stdio.h>
#include <stdlib.h>
int num[20000001];
int find[500001];
int compare(const void *p, const void *q){
    int num1 = *(int *)p, num2 = *(int *)q;
    if (num1 > num2) return 1;
    else if (num1 < num2) return -1;
    return 0;
}
int binsearch(int *card, int n, int target){
    int stt = 0, end = n-1;
    while (stt <= end){
        int mid = (stt + end) / 2;
        if (card[mid] < target){
            stt = mid + 1;
        }
        else if (card[mid] > target){
            end = mid - 1;
        }
        else return 1;
    }
    return 0;
}
int main(){
    int i, n; scanf("%d", &n);
    int card[n];
    for (i = 0 ; i < n ; ++i){ 
        scanf("%d", &card[i]);
        num[card[i]+10000000]++;
    }
    qsort(card, n, sizeof(int), compare);
    int m; scanf("%d", &m);
    for (i = 0 ; i < m ; ++i) scanf("%d", &find[i]);
    for (i = 0 ; i < m ; ++i){
        binsearch(card, n, find[i]);
        printf("%d ", num[find[i]+10000000]);
    }  
    return 0;
}
