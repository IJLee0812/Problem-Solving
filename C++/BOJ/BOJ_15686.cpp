#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct Point{
    int x, y;
};

int N, M, val, min_city_dist = 1e9;
vector<Point> houses; // 집
vector<Point> chickens; // 치킨집
vector<Point> selected; // 백트래킹으로 선택한 M개의 치킨집

void input(){
    cin >> N >> M;

    for (int i = 1 ; i <= N ; ++i){
        for (int j = 1 ; j <= N ; ++j){
            cin >> val;
            if (val == 1) houses.push_back({i, j});
            else if (val == 2) chickens.push_back({i, j});
        }
    }
}

int taxi_dist(Point p1, Point p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void calculate_dist(){
    int curr_dist = 0;

    for (const auto& house : houses){
        int min_dist = 1e9;

        for (const auto& chicken : selected){
            int dist = taxi_dist(house, chicken);
            if (dist < min_dist) min_dist = dist;
        }

        curr_dist += min_dist;
    }

    // 최소 도시 치킨 거리 갱신
    if (curr_dist < min_city_dist) min_city_dist = curr_dist;
}


void DFS(int idx, int count){
    // 종료조건
    if (count == M){
        calculate_dist();
        return;
    }

    for (int i = idx ; i < chickens.size() ; ++i){
        selected.push_back(chickens[i]);
        DFS(i + 1, count + 1);
        selected.pop_back();  // 백트래킹
    }
}

void solve(){
    DFS(0, 0);
    cout << min_city_dist;
}


int main(){
    fastio
    input();
    solve();
    return 0;
}