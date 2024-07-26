#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n, 0);
    for (ll i = 0; i < q; i++) {
        ll l, r, v;
        cin >> l >> r >> v;
        a[l-1] += v;
        if (r  < n) {
            a[r] -= v;
        }
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += a[i];
        cout << sum << " ";
    }
    cout << '\n';
    return 0;
}