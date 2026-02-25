#include <stdio.h>
int main(){
    int i, n;
    double arr[1000], max = 0, sum = 0;
    scanf("%d", &n);
    for (i = 0 ; i < n ; i++){
        scanf("%lf", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }
    
    for (i = 0 ; i < n ; i++){
        arr[i] = arr[i] / max  * 100.0;
        sum += arr[i];
    }
    printf("%lf", sum/(double)n);
    
}