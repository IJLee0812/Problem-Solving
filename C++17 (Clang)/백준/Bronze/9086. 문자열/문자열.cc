#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    int test_case; cin >> test_case;
    for (int i = 0 ; i < test_case ; ++i){
        cin >> str;
        cout << str[0] << str[str.length() - 1] << '\n';
    }
    return 0;
}