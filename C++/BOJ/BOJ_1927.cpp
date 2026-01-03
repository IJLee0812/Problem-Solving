#include <iostream>
#define MAX 100001
using namespace std;
int temp, ind = 0, heap[MAX], N;

void add(int x){
    heap[++ind] = x;
    int indtmp = ind;
    while(indtmp > 1){
        if (heap[indtmp] < heap[indtmp/2]){
            temp = heap[indtmp/2];
            heap[indtmp/2] = heap[indtmp];
            heap[indtmp] = temp;
        }
        indtmp /= 2;
    }
}

int del(){
    int sol = heap[1];
    heap[1] = heap[ind--];
    int me = 1, child = 2;
    while (child <= ind){
        if (child + 1 <= ind && heap[child] > heap[child+1]) child += 1;
        if (heap[me] > heap[child]){
            int temp = heap[me];
            heap[me] = heap[child];
            heap[child] = temp;
            me = child;
            child = me * 2;
        }
        else break; // 중요! 없으면 segmentation error 발생 가능
    }
    return sol;
}

int main(){
    cin >> N;
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x;
    for (int i = 0 ; i < N ; ++i){
        cin >> x;
        if (x == 0){
            if (ind == 0) cout << "0\n";
            else cout << del() << '\n';
        }
        else{
            add(x);
        }
    }
    return 0;
}