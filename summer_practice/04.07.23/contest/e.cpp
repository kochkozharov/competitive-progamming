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
        vector<ll> d(n+1);
        d[1] = 0;
        for (ll i = 2; i < n+1; ++i) {
            ll a=1e18, b=1e18, c=1e18;
            if (i % 3 == 0 ) a = d[i/3] + i;
            if (i % 2 == 0) b = d[i/2] + i;
            c = d[i-1] +i;
            d[i] = min(min(a,b),c);
        }
        cout << d[n] << endl;
        return 0;
    }