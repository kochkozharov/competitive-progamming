#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;



int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll>in(n);
    vector<ll>mn;
    vector<ll>mx;
    for (ll i = 0; i < n; ++i) {
        cin >> in[i];
    }
    if (n == 1) {
        cout << "1 1\n1 1\n1 1\n";
        return 0; 
    }
    if (in[0] < in[1]) {
        mn.push_back(1);
    }
    else if (in[0] > in[1]) {
        mx.push_back(1);
    }
    for (ll i = 1; i < n-1; ++i) {
        if (in[i-1] < in[i] and in[i] > in[i+1]) {
            mx.push_back(i+1);
        }
        if (in[i-1] > in[i] and in[i] < in[i+1]) {
            mn.push_back(i+1);
        }
    }
    if (in[n-2] < in[n-1]) {
        mx.push_back(n);
    }
    else if (in[n-2] > in[n-1]) {
        mn.push_back(n);
    }
    ll mni=0,mxi=0;
    cout << mn.size() << ' ';
    for (ll i = 0; i < mn.size(); ++i) {
        cout << mn[i] << ' ';
        if (in[mn[i]-1] < in[mn[mni]-1]) mni = i;
    }
    cout << '\n';
    cout << mx.size() << ' ';
    for (ll i = 0; i < mx.size(); ++i) {
        cout << mx[i] << ' ';
        if (in[mx[i]-1] > in[mx[mxi]-1]) mxi = i;
    }
    cout << '\n';
    cout << mn[mni] << ' ';
    cout << mx[mxi] << endl;
    return 0;
}
