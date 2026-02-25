#include <bits/stdc++.h>
using namespace std;
int main(){
    list<char> L;
    string str; cin >> str;
    for (auto c : str) L.push_back(c);
    int t; cin >> t;
    auto cursor = L.end();
    while (t--){
        char op; cin >> op;
        if (op == 'L'){
            if (cursor != L.begin()) cursor--;
        }
        else if (op == 'D'){
            if (cursor != L.end()) cursor++;
        }
        else if (op == 'P'){
            char add; cin >> add;
            L.insert(cursor, add);
        }
        else{
            if (cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for (auto c : L) cout << c;
    return 0;
}