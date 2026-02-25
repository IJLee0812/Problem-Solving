#include <stdio.h>
#include <string.h>
int main(){

	int test_case, repeat;

	char s[21];

	scanf("%d", &test_case); 

	for (int i = 0 ; i < test_case ; i++){
		
		scanf("%d", &repeat);
		
		scanf("%s", s);
		
		for (int j = 0 ; j < strlen(s) ; j++)
			for (int k = 0 ; k < repeat  ; k++)
				printf("%c", s[j]);
        printf("\n");

	}

	return 0;

}