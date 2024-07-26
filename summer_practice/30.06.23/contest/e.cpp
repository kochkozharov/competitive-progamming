#include <bits/stdc++.h>

using namespace std;

//0 1 2 3 4 5 6 7 8 9 
//1 0 0 0 1 0 1 0 2 1

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for(string::size_type i = 0; i < s.size(); ++i) {
        if (s[i] == '4' or s[i] == '6' or s[i] == '9' or s[i] == '0') sum += 1;
        else if (s[i] == '8') sum += 2;
    }
    cout << sum;
    return 0;
}