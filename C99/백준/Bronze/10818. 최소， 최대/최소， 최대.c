#include <stdio.h>
int main(){int num, data, min = 1000001, max = -1000001;scanf("%d", &num);
    for (int i = 0 ; i < num ; i++){scanf("%d", &data);
        if (data > max)
            max = data;
        if (data < min)
            min = data;}
    printf("%d %d", min, max);
    return 0;}