#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll s = 0;
    for (ll i = 0; i < n; ++i) {
        ll mx = -1e10;
        for (ll j = i; j>=0 ; --j) {
            mx = max(mx, a[j]);
            s += mx;
        }
    }
    cout << s << endl;
    return 0;
}