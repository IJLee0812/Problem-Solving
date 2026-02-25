#include <stdio.h>
#include <string.h> 
#define MAX 2000001

int queue[MAX];
int head = 0, tail = 0;

void push(int x){
	queue[tail++] = x;
}

void pop(){
	if (head == tail){
		printf("-1\n");	
	}
	else{
		printf("%d\n", queue[head++]);
	}
}

void size(){
	printf("%d\n", tail-head);
}

void empty(){
	if (head == tail){
		printf("1\n");
	}
	else printf("0\n");
}

void front(){
	if (head == tail){
		printf("-1\n");
	}
	else printf("%d\n", queue[head]);	
}

void back(){
	if (head == tail){
		printf("-1\n");
	}
	else printf("%d\n", queue[tail-1]);
}

int main(){
	int n; scanf("%d", &n);
	char order[10];
	for (int i = 0 ; i < n ; ++i){
		scanf("%s", order); 
		if (!strcmp(order, "push")){
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (!strcmp(order, "pop"))
			pop();
		else if (!strcmp(order, "empty"))
			empty();
		else if (!strcmp(order, "front"))
			front();
		else if (!strcmp(order, "size"))
			size();
		else back();
	}
	return 0;
}