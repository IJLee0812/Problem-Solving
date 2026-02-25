#include <stdio.h>

int self(int num){
    int res = num;
    while (num > 0){
        res += num % 10;
        num /= 10;
    }
    return res;
}

int main(){
    int a[10001], i, tmp;
    for (i = 1 ; i < 10001 ; i++){
        tmp = self(i);
        if (tmp <= 10000){
            a[tmp] = 1;
        }
    }
    for (i = 1 ; i < 10001 ; i++){
        if (a[i] != 1) printf("%d\n", i);
    }
    return 0;
}