#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int s, e;
}Lec;
int compare(const void*, const void*);
int main(){
	int i,n,last=0,cnt=0; scanf("%d", &n);
	Lec* lec = (Lec*)malloc(sizeof(Lec)*n);
	for (i = 0 ; i < n ; ++i)
		scanf("%d %d", &lec[i].s, &lec[i].e);
	qsort(lec, n, sizeof(Lec), compare);
	for (i = 0 ; i < n ; ++i){
		if (lec[i].s >= last){
			cnt++;
			last = lec[i].e;
		}
	}
	printf("%d", cnt);
	return 0;
}
int compare(const void* a, const void* b){
	const Lec* n1, *n2;
	n1 = (const Lec*)a;
	n2 = (const Lec*)b;
	if (n1 -> e != n2 -> e){
		if (n1->e < n2-> e)
			return -1;
		else return 1;
	}
	else{
		if (n1->s < n2->s)
			return -1;
		else if (n1->s == n2->s)
			return 0;
		else return 1;
	}
}