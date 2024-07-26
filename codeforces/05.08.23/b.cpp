#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve();

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }     
    return 0;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i =0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    ll sum1 = 0;
    ll sum = 0;
    for (ll i =0; i < n; ++i) {
        if (a[i] == 1) ++sum1;
        else sum += a[i]-1;
    }
    if (sum1 > sum) cout << "NO\n";
    else cout << "YES\n";
}
