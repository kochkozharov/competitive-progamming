#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 200100;
const ll MOD = 1'000'000'007;

ll two[N];
ll a[N], freq[N], d[N];

void solve();

int main() {
    two[0] = 1;
    for (ll i = 1; i < N; ++i) two[i] = 2 * two[i - 1] % MOD;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}

void solve() {
    ll n;
    cin >> n;
    bool nulls = false;
    for (ll i = 0; i < n; ++i) {
        cin >> *(a + i);
        if (*(a + i) == 0) nulls = true;
        ++freq[min(a[i], n + 1LL)];
    }
    if (!nulls) {
        cout << 0 << '\n';
        for (ll i = 0; i <= n+100; ++i) freq[i] = 0;
        return;
    }
    d[n+100] = 0;
    for (ll i = n +99; i; --i)
        d[i] = d[i + 1] + freq[i];
    ll ans = 0, q = 1;
    for (ll i = 1; i <= n + 1; ++i) {
        ans = (ans + i * (q * two[d[i + 1]] % MOD)%MOD) % MOD;
        q = q * (two[freq[i]] - 1) % MOD;
    }
    ans += MOD;
    ans %= MOD;
    cout << ans << '\n';
    
    for (ll i = 0; i <= n+100; ++i) freq[i] = 0;
}