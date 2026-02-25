#include <stdio.h>

void merge(int list[], int left, int mid, int right){
	int sorted[1000000]; 
	int i = left; 
	int j = mid + 1;  
	int k = 0;  
	while(i <= mid && j <= right){ 		
		if(list[i] <= list[j])  
			sorted[k++] = list[i++]; 
		else 
			sorted[k++] = list[j++]; 
	} 
	while(i <= mid)  
		sorted[k++] = list[i++]; 
	while(j <= right)  
		sorted[k++] = list[j++]; 
	k--; 
	while(k >= 0){ 
		list[left + k] = sorted[k]; 
		k--; 
	}
}

void merge_sort(int list[], int left, int right){
    
	int mid;
    
    if (left < right){
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}
    


int main(void){
	int size, list[1000000];
    //printf("데이터 개수 입력 : ");
    scanf("%d", &size);
    //printf("정렬할 데이터 입력");
    for (int i = 0 ; i < size ; i++){
        scanf("%d", &list[i]);
	}
    merge_sort(list, 0, size-1);
    
    for(int i = 0 ; i < size ; i++)
        printf("%d\n", list[i]);
    return 0;
    
}