#include <stdio.h>
int num, sol, ten, one, sum, cycle = 0;
int main(void){
    scanf("%d", &num);
    sol = num;
    while (1){
        ten = num / 10;
        one = num % 10;
        sum = (ten + one) % 10;
        num = one * 10 + sum;    
        cycle++;
        if (sol == num){
            printf("%d", cycle);
            break;
        }
    }

    return 0;
    
}