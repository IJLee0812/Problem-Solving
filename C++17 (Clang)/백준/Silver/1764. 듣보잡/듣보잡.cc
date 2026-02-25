#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int N, M; cin >> N >> M;
    map<string, string> Map;
    string str;
    string strs[M];
    for (int i = 0 ; i < N ; ++i){
        cin >> str;
        Map[str] = str;
    }
    int count = 0;
    for (int i = 0 ; i < M ; ++i){
        cin >> str;
        if (str == Map[str]){
            strs[count] = str;
            count++;
        }
    }
    sort(strs, strs+count);
    cout << count << '\n';
    for (int i = 0 ; i < count ; ++i)
        cout << strs[i] << '\n';
    return 0;
}