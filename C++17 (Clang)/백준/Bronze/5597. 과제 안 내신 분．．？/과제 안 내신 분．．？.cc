#include <iostream>
using namespace std;
int num, arr[30];
int main(){
    for (int i = 0 ; i < 28 ; ++i){
        cin >> num;
        arr[num-1]++;
    }
    int tmp1 = 0, tmp2;
    for (int i = 0 ; i < 30 ; ++i){
        if (arr[i] == 0){
            if (tmp1 == 0) tmp1 = i + 1;
            else tmp2 = i + 1;
        }
    }
    if (tmp1 < tmp2) cout << tmp1 << '\n' << tmp2;
    else cout << tmp2 << '\n' << tmp1;
    return 0;
}