#include <iostream>
using namespace std;
int main(){
    int queue[101];
    int test_case; cin >> test_case;
    for (int i = 0 ; i < test_case ; ++i){
        int n, m, max = 0; cin >> n >> m;
        for (int j = 0 ; j < n ; ++j)
            cin >> queue[j];
        int front = 0, cnt = 1;
        while (1){
            for (int k = 0 ; k < n ; ++k)
                if (queue[k] > max)
                    max = queue[k];
            while (queue[front] != max)
                front = (front + 1) % n;
            if (front == m)
                break;
            queue[front] = 0;
            front = (front + 1) % n;
            max = 0;
            cnt++;            
        }
        cout << cnt << "\n";   
    }
}