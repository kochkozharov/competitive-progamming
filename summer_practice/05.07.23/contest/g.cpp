#include <iostream>
#include <vector>
    
using namespace std;
    
using ll = long long;
#define MOD (ll)(1e9+7)
    
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll sum = 0, p = 1;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a < 0) a += MOD;
        sum = (sum + a) % MOD;
    }
    for (ll i = 0; i < n-1; i++) {
        p = (p * 2) % MOD;
    }

    cout << (sum * p) % MOD << '\n';
    return 0;
}