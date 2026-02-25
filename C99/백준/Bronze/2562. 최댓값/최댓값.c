#include <stdio.h>
int main(){int num,max=0,list[9],ind;for(int i=0;i<9;i++){scanf("%d",&num);list[i]=num;}
for(int i=0;i<9;i++){if(list[i]>max){max=list[i];ind = i;}}
printf("%d\n%d",max,ind+1);return 0;}