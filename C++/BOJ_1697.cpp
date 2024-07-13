#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int N, K;
struct Point{
    int location, time;
};
queue<Point> myqueue;
bool visited[MAX] = { false };
void BFS(){
    while(!myqueue.empty()){
        Point curr = myqueue.front();
        myqueue.pop();
        visited[curr.location] = true;
        if (curr.location == K){
            cout << curr.time << '\n';
            break;
        }
        int nl1 = curr.location - 1;
        int nl2 = curr.location + 1;
        int nl3 = curr.location * 2;
        if (nl1 >= 0 && !visited[nl1]){
            myqueue.push({nl1, curr.time + 1});
        }
        if (nl2 < MAX && !visited[nl2]){
            myqueue.push({nl2, curr.time + 1});
        }
        if (nl3 < MAX && !visited[nl3]){
            myqueue.push({nl3, curr.time});
        }
    }
}

int main(){
    cin >> N >> K;
    myqueue.push({N, 0});
    BFS();
    return 0;
}