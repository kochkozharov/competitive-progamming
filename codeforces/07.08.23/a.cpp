#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solve();

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num % 2 == 1) ++odd;
        else ++even;
    }
    if (odd == 1 && even == 1){
        cout << "no\n";
        return;
    }
    if (abs(odd-even)%2 == 1 && odd != 1 && even != 1){
        cout << "no\n";
        return;
    }
    cout << "yes\n";
}

//неч + неч = чет
//чет + неч = неч
//чет + чет = чет