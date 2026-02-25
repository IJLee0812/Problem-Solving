#include <stdio.h>
#include <string.h>
#define MX 100000
int deque[2*MX+1];
int head = MX,  rear = MX;
void push_front(int x){
	if (head != -1){
		deque[--head] = x;
	}
}
void push_back(int x){
	if (rear != 2*MX){		
		deque[rear++] = x;
	}
}
void pop_front(){
	if (rear-head == 0)
		printf("-1\n");
	else{
		printf("%d\n", deque[head++]);
	}
}
void pop_back(){
	if (rear-head == 0)
		printf("-1\n");
	else{
		printf("%d\n", deque[rear-1]);
		rear--;
	}
}
void size(){
	printf("%d\n", rear-head);
}
void empty(){
	if (rear-head == 0)
		printf("1\n");
	else printf("0\n"); 
}
void front(){
	if (rear-head == 0)
		printf("-1\n");
	else printf("%d\n", deque[head]);
}
void back(){
	if (rear-head == 0)
		printf("-1\n");
	else printf("%d\n", deque[rear-1]);
}
int main(){
	int n;scanf("%d", &n);
	char order[12];
	for (int i = 0 ; i < n ; ++i){
		scanf("%s", order);
		int num; 
		if (!strcmp(order, "push_back")){
			scanf("%d", &num);
			push_back(num);	
		}
		else if (!strcmp(order, "push_front")){
			scanf("%d", &num);
			push_front(num);
		}
		else if (!strcmp(order, "front")){
			front();	
		}
		else if (!strcmp(order, "back")){
			back();	
		}
		else if (!strcmp(order, "empty")){
			empty();	
		}
		else if (!strcmp(order, "pop_front")){
			pop_front();	
		}
		else if (!strcmp(order, "pop_back")){
			pop_back();
		}
		else size();
	}
	return 0;
}