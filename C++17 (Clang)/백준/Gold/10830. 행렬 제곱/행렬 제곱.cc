#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<long long>>;

long long N, B;

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

Matrix operator*(const Matrix& a, const Matrix& b){
    Matrix c(N, vector<long long>(N, 0));

    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j){
            for (int k = 0 ; k < N ; ++k){
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= 1000;
            }
        }
    }

    return c;
}

Matrix power(Matrix a, long long b){
    if (b == 1){
        for (int i = 0 ; i < N ; ++i)
            for (int j = 0 ; j < N ; ++j)
                a[i][j] %= 1000;

        return a;
    }

    Matrix half = power(a, b / 2);

    Matrix result = half * half;

    if (b % 2 == 1) result = result * a;

    return result;
}


int main(){
    fastio();
    cin >> N >> B;

    Matrix A(N, vector<long long>(N, 0));

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            cin >> A[i][j];

    Matrix result = power(A, B);

    for (int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N ; ++j)
            cout << result[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}