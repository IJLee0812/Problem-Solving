#include <stdio.h>
#include <string.h>
int stack[100];
int top = -1;
int push(char c){
    if (top >= 99){
        return -1;
    }
    else return stack[++top] = c;
}
int pop(){
    if (top < 0) return -1;
    return stack[top--] = '\0';
}
char check(){
    return stack[top];
}
void func(char *c, int len){
    for (int i = 0 ; i < len ; ++i){
        if (c[i] == '[' || c[i] == '(' || c[i] == ']' || c[i] == ')'){
            if (top == -1) push(c[i]);
            else{
                if (check() == '(' && c[i] == ')') pop();
                else if (check() == '[' && c[i] == ']') pop();
                else push(c[i]); 
            }
        }
    }
    if (top == -1) printf("yes\n");
    else printf("no\n");
}
int main(){
    char str[100];
    while (1) {
        top = -1;
        gets(str);
        if (strcmp(str, ".") == 0) break;
        func(str, strlen(str));
    }
    return 0;
}