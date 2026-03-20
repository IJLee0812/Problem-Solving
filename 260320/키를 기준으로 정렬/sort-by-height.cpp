#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

struct Person{
    string name;
    int height;
    int weight;

    bool operator<(const Person& p) const{
        return height < p.height;
    }
};
vector<Person> people;

int main() {
    cin >> n;

    string name;
    int height;
    int weight;

    for (int i = 0; i < n; ++i){
        cin >> name >> height >> weight;
        people.push_back({name, height, weight});
    }

    sort(people.begin(), people.end());

    for (const auto &person : people)
        cout << person.name << " " << person.height << " " << person.weight << '\n';

    return 0;
}