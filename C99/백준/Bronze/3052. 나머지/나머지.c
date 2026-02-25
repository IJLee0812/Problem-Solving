#include <stdio.h>
int main(){
    int n,i,r=0,a[42]={0,};
    for(i=0;i<10;i++){
        scanf("%d",&n);
        a[n%42]++;
    }
    for(i=0;i<42;i++)
        if(a[i]!=0)r++;
    printf("%d",r);
    return 0;
}