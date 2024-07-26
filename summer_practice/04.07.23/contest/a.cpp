#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set> 
 
using namespace std;
 
using ll= long long;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k, m;
    cin >> n >> k >> m;
    set<ll> dan;
    while (m--) {
        ll dn;
        cin >> dn;
        dan.insert(dn);
    }
 
    ll mod = (ll)(1e9+7);
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        for (ll j =1; j<=k; ++j) {
            if (i - j < 0) {
                break;
            }
            if (dan.contains(i)) {
                dp[i]=0;
            }
            else dp[i]=(dp[i]+dp[i-j]) % mod;
        }
    }
    cout << dp[n] <<endl;
    return 0;
}