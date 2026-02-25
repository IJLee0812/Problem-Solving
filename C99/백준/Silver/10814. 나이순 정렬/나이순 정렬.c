#include <stdio.h>
typedef struct info{
	int age;
	char name[101];
}info;
info person[100001];
int main(){
	int n; scanf("%d", &n);
	int min = 200, max = -200;
	for (int i = 0 ; i < n ; ++i){
		scanf("%d %s", &person[i].age, person[i].name);

		if (min > person[i].age) min = person[i].age;

		if (max < person[i].age) max = person[i].age;
	}

	for (int i = min ; i < max+1 ; ++i)
		for (int j = 0 ; j < n ; ++j)
			if (person[j].age == i)
				printf("%d %s\n", person[j].age, person[j].name);

	return 0;
}