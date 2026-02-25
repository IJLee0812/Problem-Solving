#include <stdio.h>

int main(){
    int n, tmp, chk, cnt = 1; scanf("%d", &n);
    if (n == 1){
        printf("666\n");
        return 0;
    }
    
    for (int i = 667;;++i){
        tmp = i;
        chk = 0;
        while (tmp){
            if (tmp % 1000 == 666)
                chk++;
            tmp /= 10;
        }
        
        if (chk){
            cnt++;
            if (cnt == n){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}