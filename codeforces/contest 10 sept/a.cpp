#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

ll find_gcd(vector<ll> &arr)
{
  ll result = arr[0];
  for (ll i = 1; i < arr.size(); i++)
  {
    result = gcd(arr[i], result);
 
    if(result == 1)
    {
    return 1;
    }
  }
  return result;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll ga = find_gcd(a);
    ll gb = find_gcd(b);
    if (ga == gb) cout << 0 << nl;
    else if (ga % gb == 0 || gb % ga == 0) cout << 1 << nl;
    else cout << 2 << nl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}

