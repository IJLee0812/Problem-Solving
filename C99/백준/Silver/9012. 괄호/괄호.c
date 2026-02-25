#include <stdio.h>
char stack[51];
int top = 0;
void push(char c){
    stack[top++] = c;
}
char pop(){
    return stack[--top];
}
int isempty(){
    return (top == 0);
}
int check(char *str){
    int result = 1;
    int i;
    for (i = 0 ; str[i] ; ++i){
        if (str[i] == '(') push(str[i]);
        else{
            if (isempty()){
                result = 0;
                break;
            }
            else pop();
        }
    }
    if (!isempty()) result = 0;
    while (!isempty()) pop();
    return result;
}
int main(){
    int t;
    char str[51];
    int i;
    scanf("%d", &t);
    for (i = 0 ; i < t ; ++i){
        scanf("%s", str);
        if(check(str)) 
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}