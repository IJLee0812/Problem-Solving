#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto c : commands){
        vector<int> temp;
        int i = c[0] - 1, j = c[1] - 1, k = c[2] - 1;
        for (int l = i; l <= j ; ++l)
            temp.push_back(array[l]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
    }
    
    return answer;
}