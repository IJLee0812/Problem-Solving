#include <stdio.h>
int a,b,c,n,r,arr[10]={0};
int main(){
    scanf("%d %d %d",&a,&b,&c);
    n=a*b*c;
    while(n){
        r=n%10;
        arr[r]+=1;
        n/=10;
    }
    for(int i=0;i<10;i++)
        printf("%d\n",arr[i]); 
    
        return 0;
}