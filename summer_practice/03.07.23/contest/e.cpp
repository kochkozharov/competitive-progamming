#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
    
using ll= unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a, m, k, mod;
    cin >> a >> m >> k >> mod;
    vector<ll> c(mod);
    for (ll i = 0; i < n; ++i){
        c[a]++;
        a = (a * m + k) % mod;
    }
    ll sum = 0;
    ll i = 0;
    for (ll k = 0; k < mod; ++k) {
        for (ll j = 0; j < c[k]; ++j) {
            sum  = (sum + k*(i+1)) % (ll)(1e9+7);
            ++i;
        }
    }
    cout << sum << endl;
    return 0;
}