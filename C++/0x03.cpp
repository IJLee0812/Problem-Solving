#include <iostream>
#include <vector>
using namespace std;

void insert(int idx, int num, int arr[], int& len){
    for (int i = len ; i > idx ; --i)
        arr[i] = arr[i-1];
    arr[idx] = num;
    len++;
}

void erase(int idx, int arr[], int& len){
    len--;
    for (int i = idx ; i < len ; ++i)
        arr[i] = arr[i+1];
}

void printArr(int arr[], int& len){
    for(int i = 0; i < len; i++) cout << arr[i] << ' ';
    cout << "\n\n";
}

void insert_test(){
    cout << "***** insert_test *****\n";
    int arr[10] = {10, 20, 30};
    int len = 3;
    insert(3, 40, arr, len); // 10 20 30 40
    printArr(arr, len);
    insert(1, 50, arr, len); // 10 50 20 30 40
    printArr(arr, len);
    insert(0, 15, arr, len); // 15 10 50 20 30 40
    printArr(arr, len);
}

void erase_test(){
    cout << "***** erase_test *****\n";
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    erase(4, arr, len); // 10 50 40 30 20
    printArr(arr, len);
    erase(1, arr, len); // 10 40 30 20
    printArr(arr, len);
    erase(3, arr, len); // 10 40 30
    printArr(arr, len);
}

int main(void) {
    insert_test();
    erase_test();

    vector<int> v1(3, 5); // {5, 5, 5}
    cout << v1.size() << '\n'; // 3
    v1.push_back(7); /* {5, 5, 5, 7} 시간복잡도 O(1).

        push_back, pop_back은 시간복잡도 O(1).
        push_front, pop_front는 시간복잡도 O(N) 임에 유의해야 한다.

    */
    vector<int> v2(2); // {0, 0}
    v2.insert(v2.begin() + 1, 3); // {0, 3, 0}

    vector<int> v3 = {1, 2, 3, 4}; // {1, 2, 3, 4}
    v3.erase(v3.begin() + 2); // {1, 2, 4};

    vector<int> v4;
    v4 = v3; // 등호를 사용하면 깊은 복사(deep copy)가 일어난다. v4와 v3은 서로 다른 메모리 공간을 참조하므로 v4를 수정해도 v3에는 영향을 주지 않는다.
    cout << v4[0] << v4[1] << v4[2] << '\n'; // 124
    v4.pop_back(); // {1, 2}
    v4.clear(); // {}

    vector<int> v5 = {1, 2, 3, 4, 5, 6};
    for (int e : v5) cout << e << ' '; // 1.range-based for loop(since C++11)
    for (int i = 0 ; i < v5.size() ; ++i) cout << v5[i] << ' '; // 2.for loop
    // v5.size() - 1 이렇게 구현하면 안 됨. unsigned int로 강제 형변환 당하면서 런타임 에러 발생함
}

/*
#include <iostream>
using namespace std;
int freq[26]; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (auto c : s)
        freq[c-'a']++;
    for (int i = 0 ; i < 26 ; ++i)
        cout << freq[i] << ' ';
}
*/