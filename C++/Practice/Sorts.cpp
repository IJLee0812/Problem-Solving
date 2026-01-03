#include <iostream>
#define N 10
using namespace std;

int raw[N] = {45, 77, 12, 43, 9, 34, 23, 19, 33, 84};
int temp;

int tmp[N]; // mergesort

int heap[N], ind = 1; // heapsort

void print(){
    for (int i = 0 ; i < N ; ++i)
        cout << raw[i] << ' ';
    cout << '\n';
}

void bubblesort(){
    for (int i = 0 ; i < N-1 ; ++i){
        for (int j = 0 ; j < N - i - 1 ; ++j){
            if (raw[j] > raw[j+1]){
                temp = raw[j];
                raw[j] = raw[j+1];
                raw[j+1] = temp;
            }
        }
    }
    print();
}

void selectionsort(){
    // 최솟값 선택
    for (int i = 0 ; i < N-1 ; ++i){
        int min_ind = i;
        for (int j = i ; j < N-1 ; ++j){
            if (raw[min_ind] > raw[j]){
                min_ind = j;
            }
        }
        temp = raw[min_ind];
        raw[min_ind] = raw[i];
        raw[i] = temp;
    }
    print();
}

void insertionsort(){
    int i, j, key;
    for (i = 1 ; i < N ; ++i){
        key = raw[i];
        for (j = i-1 ; j >= 0 && raw[j] > key ; --j){
            raw[j+1] = raw[j];
        }
        raw[j+1] = key; 
    }
    print();
}

void merge(int left, int mid, int right){
    for (int i = left ; i <= right ; ++i){
        tmp[i] = raw[i];
    }
    int part1 = left;
    int part2 = mid + 1;
    int index = left;
    while (part1 <= mid && part2 <= right){
        if (tmp[part1] < tmp[part2]){
            raw[index] = tmp[part1];
            part1++;
        }
        else{
            raw[index] = tmp[part2];
            part2++;
        }
        index++;
    }
    for (int i = 0 ; i <= mid - part1; i++){
        raw[index + i] = tmp[part1 + i];
    }
}
void mergesort(int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid+1, right);
        merge(left, mid, right);
    }
}

void quicksort(int st, int en){
    if (st + 1 >= en) return;
    int pivot = raw[st];
    int l = st + 1;
    int r = en - 1;
    while(1){
        while(raw[l] <= pivot && l <= r) l++;
        while(raw[r] >= pivot && l <= r) r--;
        if (l > r) break;
        temp = raw[l];
        raw[l] = raw[r];
        raw[r] = temp;
    }
    temp = raw[st];
    raw[st] = raw[r];
    raw[r] = temp;
    quicksort(st, r);
    quicksort(r+1, en);
}

void shiftDown(int parentIdx, int size){
    int leftIdx = 2 * parentIdx + 1;
    int rightIdx = leftIdx + 1;
    int largeIdx = -1;
    if (leftIdx < size)
        largeIdx = leftIdx;
    if (rightIdx < size && raw[largeIdx] < raw[rightIdx])  largeIdx = rightIdx;

    if (largeIdx != -1 && raw[largeIdx] > raw[parentIdx]){
        temp = raw[largeIdx];
        raw[largeIdx] = raw[parentIdx];
        raw[parentIdx] = temp;
        shiftDown(largeIdx, size);
    }
}
void heapsort(){
    // 배열을 Maxheap으로 변경 -> Heapify
    for (int i = N / 2 - 1 ; i >= 0 ; i--){
        shiftDown(i, N);
    }
    for (int i = N - 1 ; i > 0 ; i--){
        temp = raw[0];
        raw[0] = raw[i];
        raw[i] = temp;
        shiftDown(0, i);
    }
}

int main(){
    // bubblesort();
    // selectionsort();
    // insertionsort();
    // mergesort(0, N-1); print();
    // quicksort(0, N); print();
    heapsort(); print();
    return 0;
}