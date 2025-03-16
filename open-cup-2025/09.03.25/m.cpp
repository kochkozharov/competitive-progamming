#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <string>
#include "string"
#include "climits"
#include "vector"
using namespace std;
using ll = long long;

int main() {
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> dp(n+1);
    for (ll i = 1; i < n+1; ++i) {
        if (s[i-1] == 'P') {
            dp[i]=dp[i-1];
        } else {
            dp[i] = min(dp[i-1]+2, i);
        }
    }
    reverse(s.begin(), s.end());
    vector<ll> rdp(n+1);
    for (ll i = 1; i < n+1; ++i) {
        if (s[i-1] == 'P') {
            rdp[i]=rdp[i-1];
        } else {
            rdp[i] = min(rdp[i-1]+2, i);
        }
    }
    ll mn = LLONG_MAX;
    for (ll i = 0; i < n; ++i) {
        mn = min(dp[i]+rdp[n-i], mn);
    }
    cout << mn;
}