#include <iostream>
#include <algorithm>
using namespace std;

int k[101][100001]; // 물품 수 / 무게

struct thing{
    int weight;
    int value;
}; 

int main(){
  
    int N, K; cin >> N >> K;
    thing things[N+1];
    for (int i = 1 ; i <= N ; ++i){
        cin >> things[i].weight >> things[i].value;
    }
    for (int i = 1 ; i <= N ; ++i){
        for (int j = 1 ; j <= K ; ++j){
            if (things[i].weight > j)
                k[i][j] = k[i-1][j];
            else 
                k[i][j] = max(k[i-1][j], k[i-1][j-things[i].weight] + things[i].value);
        }
    }
    cout << k[N][K];
    return 0;
}