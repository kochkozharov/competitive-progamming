#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}

void solve() {
    int x, y;
    cin >> x >> y;
    int p = y*x;
    int q = 100 - y;
    if (q == 0) cout << -1 << nl;
    else if (p%q == 0) cout << x + p/q << nl;
    else cout << x + p/q + 1 << nl;
}