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
    if (cur & (1 << x)) cout << "1\n";
    else cout << "0\n";
}
void toggle(int x){
    cur = cur ^ (1 << x);
}
void all(){
    cur = -1;
}
void empty(){
    cur = 0;
}
int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    string str;
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