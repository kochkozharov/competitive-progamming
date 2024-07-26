#include <bits/stdc++.h>
    
using namespace std;
    
using ll = long long;
    
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, pos, su1;
    
    string s, s1;
    char x;
    vector <int> m(17, 0);
    su1 = 0;
    
    while (cin>>s)
    {
        pos = s.find('.');
        a = stoll(s.substr(0, s.find(".")));
        s1 = s.substr(s.find(".")+1, 15);
        reverse(s1.begin(), s1.end());
        for (int i = 0; i <= 14; i++)
        {
            x = s1[i];
            if (m[i] + int(x) - 48 >= 10)
            {
                m[i] = m[i] + int(x) - 58;
                m[i + 1] += 1;
            }
            else
                m[i] += int(x)-48;
        }
        su1 += a;
    }
    cout << su1 + m[15] << ".";
    for (int i = 0; i <= 14; i++)
    {
        cout << m[14-i];
    }
    return 0;
}