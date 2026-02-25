#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int len, sum = 0;
	char num[8][4] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
	char s[15], str1[2], str2[2]; scanf("%s", s);
	len = strlen(s);
	for (int i = 0 ; i < len ; i++){
		str1[0] = s[i];
		str1[1] = '\0';
		for (int j = 0 ; j < 8 ; j++){
			for (int k = 0 ; k < 4 ; k++){
				str2[0] = num[j][k];
				str2[1] = '\0';
				if (strcmp(str1, str2) == 0)
					sum += j + 3;
			}
		}
	}
	printf("%d", sum);
	return 0;
}