#include <bits/stdc++.h>
using namespace std;

int N, M, num, val, n, p;

vector<vector<int>> party;
queue<int> truth;

bool isMatch(vector<int> v, int t){
    auto iter = find(v.begin(), v.end(), t);
    if (iter != v.end()) return true; // 있을 경우 : 이터레이터 iter가 t와 동일한 값을 가진 지점에서 멈추므로 끝까지 가지 않음
    else return false; // 없을 경우 : 이터레이터가 끝까지 감
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    cin >> num;

    while (num--){
        cin >> val;
        truth.push(val);
    }

    for (int i = 0 ; i < M ; ++i){
        cin >> n;
        vector<int> tmp;

        while (n--){
            cin >> p;
            tmp.push_back(p);
        }

        party.push_back(tmp); // vector<int> 를 원소로 갖는 vector
    }
    // - - - input - - - 

    // - - - logic - - -
    while (!truth.empty()){
        int t = truth.front();
        truth.pop();

        for (int i = 0 ; i < party.size() ; ++i){
            if (isMatch(party[i], t)){
                // 진실된 사람이 속한 파티
                for (auto it : party[i]) truth.push(it); // i + 1 번째 파티에 참여한 모든 사람을 큐에 넣음
                party.erase(party.begin() + i); // 모든 사람을 큐에 넣었으므로, 파티 삭제
                i--;
            }
        }
    }

    cout << party.size();
    return 0;
}