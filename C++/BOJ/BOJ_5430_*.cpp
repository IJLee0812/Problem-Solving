#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int T; cin >> T;
    string functions;
    int nums;
    string numarrstr;
    for (int i = 0 ; i < T ; ++i){
        cin >> functions;
        cin >> nums;
        cin >> numarrstr;
        int numarr[nums], idx = 0;
        string temp = "";
        bool isEmpty = false, isError = false;
        if (numarrstr.size() == 2) isEmpty = true;
        if (!isEmpty){
            for (int j = 1 ; j < numarrstr.size() ; ++j){
                if (numarrstr[j] == ',' || numarrstr[j] == ']'){
                    numarr[idx++] = stoi(temp);
                    temp = "";
                }
                else temp += numarrstr[j];
            }
        }
        int Didx = 0;    
        for (int j = 0 ; j < functions.size() ; j++){
            if (functions[j] == 'R' && !isEmpty){
                idx = nums - 1; // 재활용
                int tempnumarr[nums]; // tempnumarr[idx--] = numarr[k];
                for (int k = 0 ; k < nums ; ++k)
                    tempnumarr[idx--] = numarr[k];
                for (int k = 0 ; k < nums ; ++k)
                    numarr[k] = tempnumarr[k];
                
            }   
            else if (functions[j] == 'D'){
                if (isEmpty){
                    cout << "error" << '\n';
                    isError = true;
                    break;
                }
                if (++Didx == nums) isEmpty = true;
            }
        }
        if (!isError){
            cout << "[";
            for (int i = Didx ; i < nums ; ++i){
                if (i == nums - 1) cout << numarr[i];
                else cout << numarr[i] << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}
