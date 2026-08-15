#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    int h = 0;
    for (int i = 0 ; i < citations.size() ; ++i){
        if (citations[i] >= i + 1) h++;
        else break;
    }
    
    return h;
}

/*

[3, 0, 6, 1, 5]

[6, 5, 3, 1, 0]

h = 0
6 >= h? h++ h = 1
5 >= h? h++ h = 2
3 >= h? h++ h = 3
1 >= h? no. return.
*/