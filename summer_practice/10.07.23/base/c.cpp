#include <bits/stdc++.h>

using ll = int64_t;

const ll MOD = 1e9 + 7;
const ll B = 31;

#define all(x) (x).begin(), (x).end()

using namespace std;

const ll MAX_N = 1e6;

int main() {
    vector<ll> b_pow(MAX_N + 1);
    b_pow[0] = 1;
    for (ll i = 1; i <= MAX_N; ++i) {
        b_pow[i] = (b_pow[i - 1] * B) % MOD;
    }
    string t, p;
    cin >> p >> t;
    ll n = t.size();
    ll m = p.size();
    vector<ll> pref(n + 1);
    for (ll i = 1; i <= n; ++i) {
        pref[i] = (pref[i - 1] * B + (t[i - 1] - 'a' + 1)) % MOD;
    }
    ll hp = 0;
    for (ll i = 0; i < m; ++i) {
        hp = (hp * B + p[i] - 'a' + 1) % MOD;
    }
    ll cnt = 0;
    for (ll i = 0; i < n - m + 1; ++i) {
        ll l = i + 1;
        ll r = (i + m - 1) + 1;
        ll h_sub = (pref[r] - (pref[l - 1] * b_pow[m]) % MOD) % MOD;
        if (h_sub < 0) {
            h_sub += MOD;
        }
        if (h_sub == hp) {
           ++cnt;
        }
    }
    cout << cnt << endl;
}
