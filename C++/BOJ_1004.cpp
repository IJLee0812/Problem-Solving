#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int x_1, y_1, x_2, y_2, cx, cy, r, T, n;

struct midpoint {
    int cx, cy;
};

struct planet {
    midpoint c;
    int r;
};

int point_distance(int x, int y, midpoint c) {
    int cx = c.cx;
    int cy = c.cy;
    return (x - cx) * (x - cx) + (y - cy) * (y - cy); // 점과 점 사이 거리 제곱 계산
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> T;

    while (T--) {
        cin >> x_1 >> y_1 >> x_2 >> y_2; // 출발점 (x_1, y_1), 도착점 (x_2, y_2)

        cin >> n;

        vector<planet> planets;

        for (int i = 0; i < n; ++i) {
            cin >> cx >> cy >> r;
            planets.push_back({{cx, cy}, r});
        }

        int cnt = 0;
        for (auto planet : planets) {
            int rsquared = planet.r * planet.r; // 반지름 제곱
            bool start_inside = rsquared > point_distance(x_1, y_1, planet.c);
            bool end_inside = rsquared > point_distance(x_2, y_2, planet.c);

            // 출발점과 도착점 중 하나만 행성 내부에 있는 경우에만 카운트 증가
            if (start_inside != end_inside) cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}