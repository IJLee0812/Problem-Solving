#include <iostream>
using namespace std;
int cur = 0;
void add(int x){
    cur = cur | (1 << x);
}
void remove(int x){
    cur = cur & ~(1 << x);
}
void check(int x){
    if (cur & (1 << x)) cout << "1\n"; // if 문 안 수식은 참일 때 그 비트만 1이고 나머지는 0이므로 항상 0보다 큼
    else cout << "0\n"; // 거짓일 때 모든 비트가 0이 되므로 값이 0이 됨.
}
void toggle(int x){
    cur = cur ^ (1 << x);
}
void all(){
    cur = -1; // 부호 모두 1로 변환됨.
}
void empty(){
    cur = 0;
}
int main(){
    ios::sync_with_stdio(0)
;    string str;
    int M, num; cin >> M;
    for (int i = 0 ; i < M ; ++i){
        cin >> str;
        if (str == "add"){
            cin >> num;
            add(num);
        }
        if (str == "remove"){
            cin >> num;
            remove(num);
        }
        if (str == "check"){
            cin >> num;
            check(num);
        }
        if (str == "toggle"){
            cin >> num;
            toggle(num);
        }
        if (str == "all"){
            all();
        }
        if (str == "empty"){
            empty();
        }
    }
    return 0;
}