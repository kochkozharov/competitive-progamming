#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> p(n+1);
    ll mnp = 0;
    ll mni = 0;
    ll mx = -1e10;
    ll mxi = -1;
    ll mem = 0;
    for (ll i = 1; i < n+1; ++i) {
        ll el;
        cin >> el;
        p[i] = p[i-1] + el;
        if (p[i] - p[mni] > mx) {
            mx = p[i] -  p[mni];
            mxi = i;
            mem = mni;
        }
        if(p[i] < mnp) {
            mnp = p[i];
            mni = i;
        }
    }
    if (mx > 0) cout << mem +1<< ' ' << mxi +1<< ' ' <<  endl;
    else cout << "-1 -1" << endl;
    return 0;
}