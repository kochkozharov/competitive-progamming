#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
    
using ll = long long;
#define MOD (ll)(1e9+7)
    
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll ind = upper_bound(a.begin()+i, a.end(), a[i]+k) - a.begin() - 1;
        ans += (ind-i-1) * (ind - i -1 +1) / 2;
    }
    cout << ans << endl;
    return 0;
}