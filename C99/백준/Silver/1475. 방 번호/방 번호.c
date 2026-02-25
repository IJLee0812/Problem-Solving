#include <stdio.h>
#include <string.h>
#define MAX(a,b) a>b?a:b
char n[1000001];
int main() {
    int res = 0, num[10] = { 0 };
    scanf("%s", n);
    for (int i = 0; i < strlen(n); i++)
        num[n[i] - '0']++;
    for (int i = 0; i < 10; i++) 
        if (i != 6 && i != 9) res = MAX(num[i], res);
    res = MAX((num[6] + num[9] + 1) / 2, res);
    printf("%d\n", res);
    return 0;
}