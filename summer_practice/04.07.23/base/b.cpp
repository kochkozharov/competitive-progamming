#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define INF (1e18)

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> dp(n, 1);
    vector<ll> prev(n, -1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < i;  ++j) {
            if (a[j] < a[i] and dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    ll pos = 0;
    ll len = dp[0];
    for (ll i =0; i < n; ++i) {
        if (dp[i] > len) {
            len = dp[i];
            pos = i;
        }
    } 
    cout << len  << '\n';
    vector<ll> path;
    while (prev[pos] != -1) {
        path.push_back(pos);
        pos = prev[pos];
    }
    path.push_back(pos);
    reverse(path.begin(), path.end());
    for (auto l : path) {
        cout << l +1<< ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}