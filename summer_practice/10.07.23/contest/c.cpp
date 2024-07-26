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
    string s;
    cin >> s;
    string temp = s;
    reverse(temp.begin(),temp.end());
    vector<ll> z = z_function(s + '#' + temp);
    ll mx = 0;
    for(ll i = s.size()+1;i<z.size();++i)
        if (z[i] == s.size() - (i - s.size() -1)) {
            mx = z[i];
            break;
        }
    cout << mx << "\n";
    return 0;
}