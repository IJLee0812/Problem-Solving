#include <bits/stdc++.h>
using namespace std;

int arr[100001], ind = 0; // 힙. 인덱스 1부터 사용

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void del(){
    cout << arr[1] << '\n';
    swap(arr[1], arr[ind--]);
    int me = 1, child = 2;

    while(child <= ind){
        if (child + 1 <= ind && arr[child] < arr[child + 1]) child += 1; // L/R 자식 중 큰 값이 child 인덱스 값이 됨
        if (arr[me] < arr[child]){
                swap(arr[me], arr[child]);
                me = child;
                child = me * 2; // me에다 2를 곱하면, 무조건 아래 레벨 왼쪽 자식을 가리키게 됨
        }
        else break;
    }

}

void add(int x){
    arr[++ind] = x;
    int tmpind = ind;

    while (tmpind > 1){
        if (arr[tmpind] > arr[tmpind / 2]){ // 부모가 더 작으면 swap
            swap(arr[tmpind], arr[tmpind / 2]);
            tmpind /= 2;
        }
        else break; // 부모가 더 크면 루프 탈출
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, x; cin >> N;

    for (int i = 0 ; i < N ; ++i){
        cin >> x;

        if (x == 0){
            if (ind == 0) cout << "0\n";
            else del();
        }
        else add(x);
    }

    return 0;
}
