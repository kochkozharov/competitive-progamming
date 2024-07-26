#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve();

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }     
    return 0;
}

ll mex(vector<ll> arr, ll N)
{
 
  // sort the array
  sort(arr.begin(), arr.end());
 
  ll mex = 0;
  for (ll idx = 0; idx < N; idx++)
  {
    if (arr[idx] == mex)
    {
      // Increment mex
      mex += 1;
    }
  }
 
  // Return mex as answer
  return mex;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i)
        cin >> v[i];
    ll save = mex(v, n);
    for (ll i = 0; i < (n * k) % ((n+1)*n); ++i) {
        ll temp = v[i%n];
        v[i%n] = save;
        save = temp;
    }
    for (auto q : v) {
        cout << q << ' ';
    }
    cout << '\n';
}
/*
1 2 3 4 5 
0 2 3 4 5
0 1 3 4 5
0 1 2 4 5
0 1 2 3 5
0 1 2 3 4
-
5 1 2 3 4
5 0 2 3 4
5 0 1 3 4
5 0 1 2 4
5 0 1 2 3
-
4 0 1 2 3
4 5 1 2 3
4 5 0 2 3
4 5 0 1 3
4 5 0 1 2
-
3 5 0 1 2
3 4 0 1 2
3 4 5 1 2
3 4 5 0 2
3 4 5 0 1
-
2 4 5 0 1
2 3 5 0 1
2 3 4 0 1
2 3 4 5 1
2 3 4 5 0
-
1 3 4 5 0
1 2 4 5 0
1 2 3 5 0
1 2 3 4 0
1 2 3 4 5
*/