#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int sum = brown / 2 + 2;
    int area = brown + yellow;
    
    int diff = sqrt(sum * sum - 4 * area); // b^2 - 4ac
    int w = (sum + diff) / 2, h = (sum - diff) / 2;
    return {w, h};
}