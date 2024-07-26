#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

struct cord {
    ll x;
    ll y;
};
void solve() {
    ll n, m, k;
    cord vika;
    cin >> n >> m >> k >> vika.x >> vika.y;
    vector<cord> ps;
    for (ll i = 0; i < k; ++i) {
        cord p;
        cin >> p.x >> p.y;
        ps.push_back(p);
    }
    for (cord p : ps) {
        if ((abs(p.x- vika.x) + abs(p.y - vika.y)) % 2 == 0){
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
