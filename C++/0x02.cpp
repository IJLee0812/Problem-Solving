#include <iostream>
#include <vector>
using namespace std;

void func(int arr[]){
    arr[0] = 10;
}

void func1(vector<int> v){
    v[10] = 7;
}

void swap(int& a, int& b){ // 참조자
    int tmp = a;
    a = b;
    b = tmp;
}

bool cmp1(vector<int> v1, vector<int> v2, int idx){
    return v1[idx] > v2[idx];
} // O(N). 이유 : 복사본을 보낼 때 N번의 과정이 필요함. 따라서 O(2N) = O(N). 
bool cmp2(vector<int>& v1, vector<int>& v2, int idx){
    return v1[idx] > v2[idx];
} // O(1).

int main(){
    ios_base::sync_with_stdio(0); // printf와 cout을 섞어 쓰면 절대 안된다. 순서가 꼬인다.
    // cin.tie(0); -> cin 명령을 수행하기 전에 cout 버퍼를 비울 필요가 없을 경우, 즉 온라인 저지 사이트 답안 제출 시 사용하여 시간(런타임)을 절약한다.

    int arr[3] = {1, 2, 3};
    func(arr);
    cout << arr[0] << endl;

    vector<int> v(100);
    func1(v);
    cout << v[10] << endl; // STL도 함수 인자로 실어 보내면 복사본을 만들어서 보내기 때문에 원본에 영향을 주지 않음. 따라서 0 출력.

    return 0;
}