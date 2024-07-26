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
    string s1, s2;
    cin >> s1 >> s2;
    vector<ll> z = z_function(s2 + '#' + s1+s1);
    for (ll i = (ll) s2.size()+1; i < (ll) z.size(); ++i) {
        if (z[i] == (ll) s2.size()) {
            if (i - s2.size()  - 1 == 0) {
                cout << 0 << '\n';
                return 0;
            }
            cout << s2.size() - (i - s2.size()  - 1) << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
