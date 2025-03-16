#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Building {
    int s;
    int w;
    int h;
};

bool operator<(const Building &a, const Building &b) {
    return a.s < b.s;
}

int main() {
    int n;
    cin >> n;
    vector<Building> buildings;
    for (int i = 0; i < n; ++i) {
        int s, w, h;
        cin >> s >> w >> h;
        buildings.push_back({s, w, h});
    }
    sort(buildings.begin(), buildings.end());

    int vert = buildings[0].h;
    int horiz = 100;

    for (int i = 1; i < n; ++i) {
        auto prev = buildings[i-1];
        auto cur = buildings[i];
        if (prev.s+prev.w == cur.s) {
            vert+=abs(prev.h - cur.h);
        }
        else {
            vert+=prev.h+cur.h;
        }
    }

    vert+=buildings[n-1].h;
    cout << horiz + vert;
}