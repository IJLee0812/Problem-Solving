#include <stdio.h>
#include <string.h>
int main(){
	int sum, len, i;
	char s[100];
	scanf("%s",s);
	sum = len = strlen(s);
	for (i = 0 ; i < len ; i++){
		if (s[i] == '=' || s[i] == '-') // =, -는 알파벳이 아니므로 혼자 못 씀
			sum--;
		if ((s[i] == 'l' || s[i] == 'n') && (s[i+1] == 'j')) // lj, nj
			sum--;
		if (s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '=') // dz= 
			sum--;
	}
	printf("%d", sum);
	return 0;
}