#include <iostream>
#include <map>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M; cin >> N >> M;
    map<string, string> Map;
    string x, y;
    for (int i = 0 ; i < N ; ++i){
        cin >> x >> y;
        Map[x] = y;
    }

    for (int i = 0 ; i < M ; ++i){
        cin >> x;
        cout << Map[x] << '\n';
    }
    return 0;
}