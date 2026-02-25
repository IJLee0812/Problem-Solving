#include <stdio.h>
#include <stdlib.h>
#define SIZE 500000
int queue[SIZE], res[SIZE];
int front = -1, rear = -1;
void push(int n){
    queue[++rear] = n;
}
int pop(){
    if (front != rear){
        return queue[++front];
    }
    else return -1;
}
int main(){
    int n, k, i, cnt = 0; scanf("%d %d", &n, &k);
    printf("<");
    for (i = 0 ; i < n ; ++i)
        push(i+1);
    while (front != rear){
        for (i = 0 ; i < k - 1 ; ++i)
            push(pop());
        res[cnt] = pop();
        cnt++;
    }
    for (i = 0 ; i < n-1 ; ++i)
        printf("%d, ", res[i]);
    printf("%d>", res[i]);
    return 0;
}