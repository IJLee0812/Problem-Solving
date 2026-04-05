#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    int sum = 0;
    vector<string> strings;
    
    for (int i = 0 ; i < numbers.size() ; ++i){
        strings.push_back(to_string(numbers[i]));
        sum += numbers[i];
    }
    
    if (sum == 0) return "0";
    
    auto comp_ = [](auto a, auto b){
        return a + b > b + a;
    };
    
    sort(strings.begin(), strings.end(), comp_);
    
    for (int i = 0 ; i < strings.size() ; ++i) answer += strings[i];
    
    return answer;
}