#include <stdio.h>
#include <string.h>
int main(){
    int n,i,j,p,a;
    char s[80];
    scanf("%d", &n);
    
    for (i = 0 ; i < n ; i++){
        scanf("%s", s);
        p = 0; a = 1;
        for (j = 0 ; j < strlen(s) ; j++){
            if (s[j]=='O'){
                p += a; a++;
            }
            else
                a = 1;
        }
        printf("%d\n",p);
    }
    return 0;
}