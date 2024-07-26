#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
 
using namespace std;
 
using ll= long long;
 
int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    vector<vector<ll>> d(n, vector<ll>(m, 0));
    d[0][0] = g[0][0];
    for (ll i = 1; i < n or i < m; ++i) {
        if (i < n) d[i][0] = g[i][0] + d[i-1][0];
        if (i < m) d[0][i] = g[0][i] + d[0][i-1];
    }
    for (ll i = 1; i < n; ++i) {
        for (ll j = 1; j < m; ++j) {
            d[i][j] = max(max(d[i-1][j], d[i][j-1]),d[i-1][j-1]) + g[i][j];
        }
    }
    cout << d[n-1][m-1] << endl;
    return 0;
}