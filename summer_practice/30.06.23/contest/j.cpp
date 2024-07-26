#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    string sum;
    cin >> sum;
    sum.erase(remove(sum.begin(), sum.end(), '.'), sum.end());
    string n;
    while (cin >> n) {
        n.erase(remove(n.begin(), n.end(), '.'), n.end());
        while (n.size() != sum.size()) {
            if (n.size() > sum.size())
                sum.insert(0, "0");
            else
                n.insert(0, "0");
        }
        //cout << sum << '\n';
        //cout << n << '\n';
        char r=0;
        for(auto i = n.size() ; i-- > 0; ) {
            char ds = sum[i] - '0' + n[i] - '0' + r;
            sum[i] = ds % 10 + '0';
            r = ds / 10;
        }
        if (r != 0) sum.insert(0, 1, r+'0');
    }
    sum.insert(sum.size()-15, 1, '.');
    cout << sum << '\n';
    return 0;
}
