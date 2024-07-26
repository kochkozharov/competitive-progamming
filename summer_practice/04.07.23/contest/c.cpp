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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> r(n+1, vector<ll>(m+1, -1));
    while (k--) {
        ll x, y;
        cin >> x >> y;
        r[x][y] = 0;
    }
    r[0][0] = 1;
    for (ll i = 1; i < n+1 or i < m+1; ++i) {
        if (i < n+1 and r[i][0] != 0) r[i][0] = r[i-1][0];
        if (i < m+1 and r[0][i] != 0) r[0][i] = r[0][i-1];
    }
    for (ll i = 1; i < n+1; ++i) {
        for (ll j = 1; j < m+1; ++j) {
            if (r[i][j] !=0) {
                r[i][j] = (r[i-1][j] + r[i][j-1]) % (ll)(1e9+7);
            }
        }
    }
    cout << r[n][m] << endl;
    return 0;
}