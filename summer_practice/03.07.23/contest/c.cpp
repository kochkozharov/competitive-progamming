#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

using ll= long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    priority_queue<ll, std::vector<ll>, std::greater<ll> > q;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        q.push(a);
    }
    while (q.size()!=1) {
        ll a = q.top(); q.pop();
        ll b = q.top(); q.pop();
        cout << a << ' ' <<  b << '\n';
        q.push(a+b);
    }
    return 0;
}
