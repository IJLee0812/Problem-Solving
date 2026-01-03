#include <bits/stdc++.h>
using namespace std;

int parent[9];

int find(int x){ // Find 연산
    if (parent[x] == x) return x; // 배열 인덱스와 값이 같다면(루트 노드), 해당 값을 리턴함
    else return parent[x] = find(parent[x]); // x의 루트 노드를 거슬러 올라가기 위한 재귀
}

void merge(int x, int y){ // Union 연산
    x = find(x); // x의 루트 노드 찾기
    y = find(y); // y의 루트 노드 찾기

    if (x == y) return; // 루트 노드가 서로 같다면 이미 연결되어 있는 것임

    parent[y] = x; // merge 수행(배열의 y 인덱스에 x 값(루트)을 저장)
}

bool isUnion(int x, int y){ // 두 노드가 연결되어 있는지 판별하는 함수
    x = find(x);
    y = find(y);
    if (x == y) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 1 ; i <= 8 ; ++i) parent[i] = i;

    merge(1, 2);
    merge(4, 5);
    merge(5, 6);
    
    cout << "2와 4는 같은 집합인가?\n" << isUnion(2, 4) << "\n"; // false
	
    merge(1, 5);
	
    cout << "2와 4는 같은 집합인가?\n" << isUnion(2, 4) << "\n"; // true

    cout << "- - - 배열 상태 - - -\n";
    for (int i = 1 ; i <= 8 ; ++i) cout << parent[i] << ' ';
    cout << "\n- - - - - - - - - - -\n";
    
    
	return 0;
}

