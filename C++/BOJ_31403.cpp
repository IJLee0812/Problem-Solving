#include <iostream>
using namespace std;
int main(){
    int a, b, c; cin >> a >> b >> c;
    cout << a + b - c << endl;
    int r = 1;
    while (r <= b) r *= 10;
    cout << a * r + b - c << endl;
    return 0;
}

#include<stdio.h>
int get(int a){
	int r = 1;
	while(r<=a)r*=10;
	return r;
}
main(){
	int a,b,c;scanf("%d %d %d",&a,&b,&c);
	printf("%d\n%d",a+b-c,a*get(b)+b-c);
}