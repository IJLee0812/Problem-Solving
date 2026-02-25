#include <stdio.h>
#include <string.h>
int check(char ans[]){

	int len = strlen(ans), alp[26] = {0,};

	for (int j = 0 ; j < len ; j++){
		if ((ans[j] == ans[j+1]) && (alp[ans[j]-'a'] == 0)){
			alp[ans[j]-'a'] = 1;
		}
		if (ans[j] != ans[j+1] && j != len-1){
			if (alp[ans[j]-'a'] == 0)
				alp[ans[j]-'a'] = 1;
			if (alp[ans[j+1]-'a'] == 1){
				return 0;
			}
		}
	}
	return 1;
}

int main(){

	int test_case, group = 0;
	
	scanf("%d", &test_case);

	for (int i = 0 ; i < test_case ; i++){

		char ans[100];
		scanf("%s", ans);
		group += check(ans);
	}

	printf("%d\n", group);

	return 0;
}