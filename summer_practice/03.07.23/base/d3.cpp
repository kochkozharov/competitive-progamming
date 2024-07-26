#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct team {
    string name;
    int problems;
    int fine;
};

bool cmpr(team &a, team &b) {
    if (a.problems != b.problems) return a.problems > b.problems;
    if (a.fine != b.fine) return a.fine < b.fine;
    return a.name < b.name;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    return 0;
    int n;
    cin >> n;
    vector<team> a;
    while (n--) {
        team t;
        cin >> t.name >> t.problems >> t.fine;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), cmpr);
    for (auto t : a) {
        cout << t.name << '\n';
    }
    return 0;
}