#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solve();

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}

ll f(vector<ll> &a, int i, ll y) {
    if (y <= a[i]) return 0;
    else {
        if (i < gsize(a)-1 && i >= 0) return y - a[i] + f(a, i+1, y-1);
        else return 1e9;
    }
}

void solve() {
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    ll l = *max_element(all(a)), r = *max_element(all(a))+k, ans=0;
    while (l <= r) {
        ll m = (l + r) / 2;
        bool good = false;
        for (int i = 0; i < n; ++i) {
            if (f(a, i, m) <= k) good = true;
        }
        if (good) {
            ans = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    cout << ans << nl;
}
