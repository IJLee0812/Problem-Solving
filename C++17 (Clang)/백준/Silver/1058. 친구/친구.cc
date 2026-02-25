#include <bits/stdc++.h>
#define MAX 51
#define INF INT_MAX
using namespace std;

int friends[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            friends[i][j] = INF;

    string str;
    for (int i = 0 ; i < N ; ++i){
        cin >> str;
        for (int j = 0 ; j < str.length() ; ++j){
            if (str[j] == 'Y') friends[i][j] = 1;
        }
    }

    for (int k = 0 ; k < N ; ++k){
        for (int i = 0 ; i < N ; ++i){
            for (int j = 0 ; j < N ; ++j){
                if (friends[i][k] != INF && friends[k][j] != INF)
                    friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
            }
        }
    }

    int res = 0;
    for (int i = 0 ; i < N ; ++i){
        int cnt = 0;
        for (int j = 0 ; j < N ; ++j){
            if (i == j) continue; // 조금이나마 검색횟수 최적화하기 위함
            if (friends[i][j] == 1 || friends[i][j] == 2) cnt++;
        }
        res = max(res, cnt);
    }

    cout << res;

    return 0;
}