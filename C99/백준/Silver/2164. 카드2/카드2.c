#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int * arr = (int*)malloc(sizeof(int) * 1000000);
    int i, front = 1, back, cnt = 0;
    scanf("%d", &back);
    for (i = 1; i <= back; i++) 
        arr[i] = i;
    if (back == 1) 
        printf("1");
    
    while (front != back) {

        arr[front] = 0;
        front++;
        if (front == back) {
            printf("%d", arr[front]);
            break;
        }
        back++;
        arr[back] = arr[front];
        arr[front] = 0;
        front++;
    }
    free(arr);
}