#include <bits/stdc++.h>

using namespace std;

void solve() {
    pair<long long, long long> a;
    pair<long long, long long> b;
    pair<long long, long long> c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    long long dist_b = abs(a.first - b.first) + abs(a.second - b.second)+1;
    long long dist_c = abs(a.first - c.first) + abs(a.second - c.second)+1;
    if ((a.first <= b.first) == (a.second <= b.second) && (a.first <= c.first) == (a.second <= c.second)) {
        cout << min(dist_c, dist_b) << '\n';
    }
    else if ((a.first <= b.first) == (a.first <= c.first)) {
        cout << min(abs(b.first - a.first), abs(c.first - a.first))+1 << '\n';
    }
    else if ((a.second <= b.second) == (a.second <= c.second)) {
        cout << min(abs(b.second - a.second), abs(c.second - a.second)) +1<< '\n';
    }
    else cout << 1 << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long t;
    cin >> t;
    while(t--) solve();
    return 0;
}
