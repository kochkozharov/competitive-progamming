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
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3) {
        cout << 2 << endl;
        return 0;
    }
    vector<ll> a(n);
    a[0] = 1; a[1] = 1; a[2] = 2;
    for (ll i = 3; i < n; ++i) {
        a[i] = a[i-1] + a[i-3] +1;
    }
    cout << a[n-1] << endl;
    return 0;
}