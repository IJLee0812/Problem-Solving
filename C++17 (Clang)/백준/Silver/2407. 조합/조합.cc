#include <bits/stdc++.h>
using namespace std;
string d[101][101];
string f(string a, string b) {
    string c; int s=0, i=0;
    while(s || i<a.size() || i<b.size()) {
        if(i<a.size()) s+=a[i]-'0';
        if(i<b.size()) s+=b[i]-'0';
        c += s%10+'0'; s/=10; i++;
    }
    return c;
}
int main() {
    int n, m; cin>>n>>m;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=i; j++)
            if(!j || j==i) d[i][j]="1";
            else d[i][j] = f(d[i-1][j-1], d[i-1][j]);
    reverse(d[n][m].begin(), d[n][m].end());
    cout << d[n][m];
}