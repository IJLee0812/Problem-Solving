#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    map<int, string> Dogam;
    map<string, int> Dogam2;
    string pokemonname;
    for (int i = 1 ; i <= N ; ++i){
        cin >> pokemonname;
        Dogam[i] = pokemonname;
        Dogam2[pokemonname] = i;
    }
    string str;
    for (int i  = 0 ; i < M ; ++i){
        cin >> str;
        // 숫자
        if ('0' <= str[0] && str[0] <= '9') cout << Dogam[stoi(str)] << '\n';
        // 문자
        else cout << Dogam2[str] << '\n';
    }
    return 0;
}