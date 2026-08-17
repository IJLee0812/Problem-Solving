#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int area = brown + yellow;
    
    for (int i = 3 ; i <= (area / 3 + 1) ; ++i){
        if (area % i == 0){
            int j = area / i;
            int width = i > j ? i : j;
            int height = area / width;
            if ((width - 2) * (height - 2) == yellow){
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    
    
    return answer;
}