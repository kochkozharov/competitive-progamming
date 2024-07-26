#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve();

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }     
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll mx = 0;
    for (int i =0; i < n; ++i) {
        if(is_sorted(a.begin()+i, a.end())) break;
        mx = max(mx, a[i]);
    }
    cout << mx << endl;
}
