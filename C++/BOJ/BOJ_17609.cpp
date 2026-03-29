#pragma once
#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

bool isP(const string& s, int l, int r){
    while (l < r){
        if (s[l] != s[r]) return false;
        l++, r--;
    }

    return true;
}

int check_string(const string& s){
    int l = 0, r = s.length() - 1;

    while (l < r){
        if (s[l] == s[r]){
            l++, r--;
        }
        else{
            bool skip_l = isP(s, l + 1, r);
            bool skip_r = isP(s, l, r - 1);

            if (skip_l || skip_r) return 1;
            else return 2;                  
        }
    }

    return 0;
}

int main(){
    fastio
    int T;
    if (cin >> T){
        while (T--){
            string s; cin >> s;
            cout << check_string(s) << '\n';
        }
    }

    return 0;
}