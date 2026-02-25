#include <stdio.h>
int main(){
	int i,x[3],y[3],X,Y;
	for(i = 0 ; i < 3 ; i++)
        scanf("%d %d", &x[i], &y[i]);
	
	if(x[0]==x[1])X=x[2];
	else if(x[1]==x[2])X=x[0];
	else X=x[1];
	
	if(y[0]==y[1])Y=y[2];
	else if(y[1]==y[2])Y=y[0];
	else Y=y[1];

	printf("%d %d\n", X, Y);

	return 0;
}