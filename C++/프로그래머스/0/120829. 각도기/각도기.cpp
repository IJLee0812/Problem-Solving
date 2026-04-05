#include <iostream>
using namespace std;
int solution(int a){
    return a < 90 ? 1 : (a == 90 ? 2 : (a < 180 ? 3 : 4));
}

int main(){
    int a; cin >> a;
    cout << solution(a);
}