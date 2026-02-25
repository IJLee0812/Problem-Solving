#include <stdio.h>
#include <string.h>

int main(){
	int i;
	char str[100]; 
	int alp[26];

	for (i = 0 ; i < 26 ; i++)
		alp[i] = -1;

	scanf("%s", str); // 단어 S를 str 배열에 저장

	for (i = 0 ; i < strlen(str) ; i++){
		if (alp[str[i] - 'a'] == -1){
				alp[str[i] - 'a'] = i;
		}
	}

	for (i = 0 ; i < 26 ; i++)
		printf("%d ", alp[i]);

	return 0;

}