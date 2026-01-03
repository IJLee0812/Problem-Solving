#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int N, road[MAX], oil_price[MAX];

int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0 ; i < N - 1 ; ++i) cin >> road[i];
    for (int i = 0 ; i < N ; ++i) cin >> oil_price[i];

    int min_cost = INT_MAX;
    long long sum_dist = 0;

    for (int i = 0 ; i < N - 1 ; ++i){
        if (oil_price[i] < min_cost) min_cost = oil_price[i];
        sum_dist += (long long)min_cost * (long long)road[i];
    }

    cout << sum_dist;

    return 0;
}
