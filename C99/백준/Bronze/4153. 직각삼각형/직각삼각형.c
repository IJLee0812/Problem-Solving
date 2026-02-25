#include <stdio.h>

int main(){

	int x,y,r,a,b,c;
	
	while(1){
		scanf("%d %d %d", &x, &y, &r);
		if(x == 0 && y == 0 && r == 0)
			break;
        a = x*x; b = y*y; c = r*r;
		if (a + b == c || a + c == b || b + c == a)
			printf("right\n");
		else printf("wrong\n");

	}

	return 0;
}