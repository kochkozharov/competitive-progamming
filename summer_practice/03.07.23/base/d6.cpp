#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

using ll= long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin , s);
    stack<ll> st;
    for (auto c : s) {
        if (isdigit(c)) st.push(c-'0');
        else if (c != ' ') {
            ll a = st.top(); st.pop();
            ll b = st.top(); st.pop();
            switch (c) {
                case '+':
                    st.push(a+b);
                    break;
                case '-':
                    st.push(b-a);
                    break;
                case '*':
                    st.push(a*b);
                    break;
            }
        }
    }
    cout << st.top() << '\n';
    return 0;
}