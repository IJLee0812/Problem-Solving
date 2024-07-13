#include <iostream>
#include <algorithm> // fill() 
#include <vector>
#include <iterator>
#include <list>
using namespace std;
/*
const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void traverse(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert(int addr, int num){ // addr : 각 원소의 주소, 배열 상에서 몇 번지인지를 의미함
    dat[unused] = num; // 새로운 원소 생성
    pre[unused] = addr; // 새 원소의 pre 값에 삽입할 위치의 주소를 대입
    nxt[unused] = nxt[addr]; // 새 원소의 nxt 값에 삽입할 위치의 nxt 값을 대입
    if (nxt[addr] != -1) pre[nxt[addr]] = unused; // * 맨 마지막 원소의 뒤에 새 원소를 추가하는 상황이라면 삽입할 위치의 다음 원소가 존재하지 않기 때문에 pre[-1]에 접근할 수 있음
    nxt[addr] = unused; // 삽입할 위치의 nxt값을 unused로 변경
    unused++;
}

void erase(int addr){
    // * addr 다음 원소의 pre값을 addr 이전 원소의 주소값으로 변경.
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr]; // * dummy node의 존재로 인해 그 어떤 원소를 지우더라도 pre[addr]은 -1이 아님이 보장되지만, nxt[addr]은 제일 마지막 원소를 지우는 상황에서 값이 -1일 수 있기 때문이다.
}

void insert_test(){
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test(){
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(){    
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    insert_test();
    erase_test();
    
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin(); // auto t = L.begin();
    L.push_front(10); // 10 1 2
    cout << *t << '\n'; // t가 가리키는 값인 1을 출력한다.
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
    t++; // t를 한 칸 앞으로 전진, 현재 t가 가리키는 값은 2
    t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환. erase는 제거한 다음 원소의 위치를 반환한다.

    cout << *t << '\n'; // 5
    for (auto i : L) cout << i << ' '; // C++11 이상은 auto 키워드를 활용하여 간단하게 가능
    cout << '\n';
    for (list<int>::iterator it = L.begin() ; it != L.end() ; it++) cout << *it << ' '; // 새로운 iterator it을 list L의 시작을 가리키게 하여 순차적으로 원소를 출력함

    return 0;
}

// 야매 연결 리스트 풀이
/*
#define MX 100005
char dat[MX]; 
int nxt[MX], pre[MX];
int unused = 1;

void traversal(){
    int cur = nxt[0];
    while (cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert(int addr, int num){
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

int main(){    
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    string init;
    cin >> init;

    int cursor = 0;
    for (auto c : init){
        insert(cursor, c);
        cursor++;
    }

    int q; cin >> q;
    while (q--){
        char op; cin >> op;
        if (op == 'P'){
            char add; cin >> add;
            insert(cursor, add);
            cursor = nxt[cursor];
        }
        else if (op == 'L'){
            if (pre[cursor] != -1) cursor = pre[cursor];
        }
        else if (op == 'D' ){
            if (nxt[cursor] != -1) cursor = nxt[cursor];
        }
        else{
            if (cursor != 0){
                erase(cursor);
                cursor = pre[cursor];
            }
        }
    }
    traversal();
    return 0;
}
*/


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
