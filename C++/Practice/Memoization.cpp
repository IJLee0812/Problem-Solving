#include <iostream>
#include <cstring>

long long memo[51];

long long fibo(int n){
    if (n <= 1) return n;

    if (memo[n] != -1) return memo[n]; // memoization keypoint

    // using memoization
    return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main(){
    memset(memo, -1, sizeof(memo));

    long long result = fibo(50);

    std::cout << result;

    return 0;
}