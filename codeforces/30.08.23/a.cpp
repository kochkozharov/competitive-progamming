#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve();

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }     
    return 0;
}

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    int mns=0, pls=0;
    int cnt = a;
    bool all = false;
    for (int i = 0; i < q; ++i) {
        if (cnt == n) all = true;
        char c;
        cin >> c;
        if (c == '+') {
            pls++;
            cnt++;
        }
        else {
            mns++;
            cnt--;
        }
    }
    if (cnt == n) all = true;
    if (all) {
        cout << "YES\n";
    }
    else if (a + pls >= n) {
        cout << "MAYBE\n";
    }
    else cout << "NO\n";
}
