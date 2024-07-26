#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = 0;
    set<ll> st;
    ll mx = 0;
    for (ll r = 0; r < n; ++r) {
        if(!st.contains(a[r])) {
            st.insert(a[r]);
            mx = max(mx, (ll)st.size());
        }
        else  {
            while (a[l] != a[r]) {
                st.erase(a[l]);
                ++l;
            }
            ++l;
        }
    }
    cout << mx << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}