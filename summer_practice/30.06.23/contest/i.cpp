#include <iostream>

typedef unsigned long long ll;

using namespace std;

int getnum(char c) {
    if (c >= 'a' and c <= 'z') return c - 'a' + 10;
    return c - '0';
}

char fromnum(int c) {
    if (c >= 10 and c <= 36) return c + 'a' - 10;
    return c + '0';
}

int main() {
    ll a, b;
    cin >> a >> b;
    string n;
    cin >> n;
    if (n=="0") {
        cout << 0 << '\n';
        return 0;
    }
    ll exp = 0;
    ll dec = 0;
    for (auto it = n.crbegin() ; it != n.crend(); ++it) {
        ll q = 1;
        for (ll i= 0; i < exp; i++) q *= a;
        dec += q * getnum(*it);
        ++exp;
    }
    string ans;
    while(dec) {
        ans += fromnum((int)(dec % b));
        dec /= b;
    }
    for(auto it = ans.crbegin() ; it != ans.crend(); ++it) {
      	cout<<*it;
    }
    cout << '\n';
    return 0;
}