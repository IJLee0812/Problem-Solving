#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int N, B; cin >> N >> B;

    string str;
    char ch;

    while (N != 0){
        if (N % B > 9)
            ch = (N % B) - 10 + 'A';
        else
            ch = (N % B) + '0';
        
        str += ch;
        
        N /= B;
    }

    reverse(str.begin(), str.end());

    cout << str;

    return 0;
}