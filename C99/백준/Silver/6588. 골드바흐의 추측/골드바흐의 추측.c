#include<stdio.h>
#include<stdbool.h>
#define MAX 1000000
int og[MAX];
int on;
bool c[MAX+1];    
int main()
{    
    for(int i=2; i*i<=MAX; i++)
    {
        if(c[i] == false)
        {
            og[on++]=i;
        for(int j=i*i; j<=MAX; j+=i){
            c[j] = true;
        }
        }
    }
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n<=4)
            break;
        for(int j=1; j<on; j++)
        {
            if(c[n-og[j]] == false){
                    
                    printf("%d = %d + %d\n",n,og[j],n-og[j]);
                    break;
                }
        }
        
    }
    return 0;
}