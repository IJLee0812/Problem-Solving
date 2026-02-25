#include <stdio.h>
int paper[100][100];
int main()
{
    int n, px, py; scanf("%d", &n);
    int sum = 0;
    for (int i = 0 ; i < n ; ++i){
        scanf("%d", &px); scanf("%d", &py);
        for (int j = px ; j < px + 10 ; ++j){
            for (int k = py ; k < py + 10 ; ++k){
                paper[j][k] = 1;
            }
        }
    }
    for (int i = 0 ; i < 100 ; ++i){
        for (int j = 0 ; j < 100 ; ++j){
            if (paper[i][j]) sum++;  
        }
    }
    printf("%d", sum);
    return 0;
}