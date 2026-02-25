#include <stdio.h>
void h(int a,int b,int n){
	if(n==1){printf("%d %d\n",a,b);return;}
	h(a,6-a-b,n-1);
	printf("%d %d\n",a,b);
	h(6-a-b,b,n-1);
}
int main(){
	int i,n,r=1;scanf("%d",&n);
	for(i=0;i<n;++i)r*=2;printf("%d\n",r-1);
	h(1,3,n); 
	return 0;
}