#include <bits/stdc++.h>
using namespace std;

void solve(const string& functions, int numarr[], int nums) {
    bool isReverse = false;
    int leftidx = 0, rightidx = 0;
    bool isError = false;

    for (char func : functions) {
        if (func == 'R') {
            isReverse = !isReverse;
        } else if (func == 'D') {
            if (leftidx + rightidx >= nums) {
                isError = true;
                break;
            }
            if (isReverse) {
                rightidx++;
            } else {
                leftidx++;
            }
        }
    }

    if (isError) {
        cout << "error\n";
    } else {
        cout << '[';
        if (isReverse) {
            for (int i = nums - 1 - rightidx; i >= leftidx; i--) {
                cout << numarr[i];
                if (i != leftidx) cout << ',';
            }
        } else {
            for (int i = leftidx; i < nums - rightidx; i++) {
                cout << numarr[i];
                if (i != nums - rightidx - 1) cout << ',';
            }
        }
        cout << "]\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        string functions;
        int nums;
        string numarrstr;

        cin >> functions >> nums >> numarrstr;

        int numarr[nums], idx = 0;
        string temp = "";
        for (int j = 1; j < numarrstr.size(); ++j) {
            if (isdigit(numarrstr[j])) {
                temp += numarrstr[j];
            } else if (numarrstr[j] == ',' || numarrstr[j] == ']') {
                if (!temp.empty()) {
                    numarr[idx++] = stoi(temp);
                    temp = "";
                }
            }
        }

        solve(functions, numarr, nums);
    }

    return 0;
}
