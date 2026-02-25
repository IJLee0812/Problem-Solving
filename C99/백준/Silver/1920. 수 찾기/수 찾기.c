#include <stdio.h>
#include <stdlib.h>
int compare(const void *p, const void *q){
    int num1 = *(int *)p;
    int num2 = *(int *)q;
    if (num1 > num2)return 1;
    else if (num1 < num2)return -1;
    return 0;
}
int data[100001];
int binarysearch(int target, int n){
    int stt = 0, end = n-1;
    while (stt <= end){
        int mid = (stt + end) / 2;
        if (data[mid] < target){
            stt = mid + 1;
        }
        else if (data[mid] > target){
            end = mid - 1;
        }
        else return 1;
    }
    return 0;
}
int main(){
    int n; scanf("%d",&n);
    for (int i = 0 ; i < n ; ++i) scanf("%d", &data[i]);
    qsort(data, n, sizeof(int), compare);
    int m, q; scanf("%d", &m);
    for (int i = 0 ; i < m ; ++i){
        scanf("%d", &q); // q는 target이 됨
        printf("%d\n", binarysearch(q, n));
    }
    return 0;
}