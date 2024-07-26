#include <bits/stdc++.h>
using namespace std;

// 자신의 그룹이 어디에 속해있는지 리턴(root node)
int find_p(int parent[], int x){
    if (x == parent[x]) return parent[x];
    else return parent[x] = find_p(parent, parent[x]);
}

// x와 y를 같은 그룹으로 그룹화
void merge(int parent[], int x, int y){
    int px = find_p(parent, parent[x]);
    int py = find_p(parent, parent[y]);

    if (px != py){
        // 0번 그룹이 진실을 아는 사람으로 설정했기 때문에, 더 작은 그룹으로 합쳐주기 위해 해당 조건문 블록이 필요
        if (px < py) parent[py] = parent[px]; 
        else parent[px] = parent[py];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;

    int know_truth;
    cin >> know_truth;

    int parent[53];

    for (int i = 0 ; i <= N ; ++i) parent[i] = i; // 각자 자신의 그룹으로 먼저 분류

    int temp;
    for (int i = 0 ; i < know_truth ; ++i){
        cin >> temp;
        parent[temp] = 0; // 진실을 아는 사람들은 0 집합으로 분류
    }

    int Pnum, temp2;
    int arr[53][53], arrsize[53];

    for (int i = 0 ; i < M ; ++i){
        cin >> Pnum >> temp; // 파티에 오는 사람 수, 파티에 오는 첫 번째 사람

        arrsize[i] = Pnum; // 각 파티의 인원 수 저장
        arr[i][0] = temp; // 첫 번째 사람

        for (int j = 1 ; j < Pnum ; ++j){
            cin >> temp2; // (두 번째 사람부터) 파티에 오는 사람 번호
            arr[i][j] = temp2;
            merge(parent, temp, temp2);
        }
    }

    int answer = M; // 전부 거짓말을 할 경우의 수 부터 시작

    // 각 파티마다 진실을 아는 사람이 한 명이라도 있으면, 거짓말을 할 수 없음 -> 해당 파티인 경우 1 감산
    for (int i = 0 ; i < M ; ++i){
        for (int j = 0 ; j < arrsize[i] ; ++j){
            if (find_p(parent, parent[arr[i][j]]) == 0){ // 진실을 아는 사람인 경우 == 0번 그룹에 속한 경우
                answer--;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}
