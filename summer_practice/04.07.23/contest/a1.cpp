#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
 
using namespace std;
 
using ll= long long;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll l, r;
    cin >> l >> r;
    ll mod = (ll)(1e9+7);
    vector<ll> dp(r+1, 0); //1 .. r
    dp[1]=1;             //0 .. r-1
    ll sum =0;
    for (ll i = 1; i < r+1; ++i) {
        for (ll j = 2; j * i < r+1; ++j) {
            dp[i*j] +=dp[i];
        }
    }
    for (auto i = l; i < r+1; ++i ) {
        sum= (sum + dp[i])%mod;
    }
    cout << sum << endl;
    return 0;
}