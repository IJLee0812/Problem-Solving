#include <iostream>
using namespace std;
int main(){
    int a, b, c; cin >> a >> b >> c;
    cout << a + b - c << endl;
    int r = 1;
    while (r <= b) r *= 10;
    cout << a * r + b - c << endl;
    return 0;
}