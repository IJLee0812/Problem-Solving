#include <stdio.h>
#define MAX 35

void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n == 1)
    {
        printf("%c %c\n", from, to);           // from에 위치한 맨 아래 원판을 to로 옮긴다
    }
    else
    {
        hanoi_tower(n - 1, from, to, tmp);     // 1. from에 위치한, 맨 아래 원판을 제외한 모든 원판을 tmp로 옮김
        printf("%c %c\n", from, to);           // 2. from에 위치한 맨 아래 원판을 to로 옮긴다
        hanoi_tower(n - 1, tmp, from, to);     // 3. tmp에 위치한 원판을 to로 옮긴다
    }
}

void power(int x, int n, char arr[])
{
    int temp = 0;
    int last = 0;
    int cnt = 0;
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= last; j++) {
            temp = arr[j] * x;
            if (temp >= 10) {
                arr[j] = temp % 10 + cnt;
                cnt = temp / 10;
                if (j == last) {
                    arr[++last] = cnt;
                    cnt = 0;
                    break;
                }
            }
            else {
                arr[j] = temp + cnt;
                cnt = 0;
            }
        }
    }
    arr[0] -= 1;
    for (int i = last; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int n = 0;
    char result[MAX] = { 0 };
    double tmp = 0;
    scanf("%d", &n);

    power(2, n, result);
    
    if(n <= 20)
        hanoi_tower(n, '1', '2', '3');
    return 0;
}