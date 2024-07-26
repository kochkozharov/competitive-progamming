#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<ll> z_function (string s) {
    ll n = (ll) s.length();
    vector<ll> z(n);
    for (ll i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    z[0] = n;
    return z;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s, p;
    cin >> s >> p;
    vector<ll> z = z_function(p + '#' + s);
    ll reps = 0;
    for (ll i = (ll) p.size()+1; i < (ll) z.size(); ++i) {
        if (z[i] == (ll) p.size()) {
            reps += 1;
        }
    }
    if (reps != 0) cout << "TAK\n" << reps << '\n';
    else cout << "NIE\n";
    return 0;
}
