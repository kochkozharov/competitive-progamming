#include <bits/stdc++.h>

using ll = long long;

#define all(x) (x).begin(), (x).end()

using namespace std;

ll CNT = 0;

struct trie {
    struct node {
        vector<int>go = vector<int>(26);
    };

    vector<node> data;

    int nodeCreate() {
        data.emplace_back();
        CNT++;
        return (int) data.size() - 1;
    }

    trie() {
        nodeCreate();
    }

    bool canGo(int u, char c) {
        return data[u].go[c-'a'] != 0;
    }

    int go(int u, char c) {
        return data[u].go[c-'a'];
    }

    void insert(const string& s) {
        int u = 0;
        for (char c : s) {
            if (!canGo(u, c))
                data[u].go[c-'a'] = nodeCreate();
            u = go(u, c);
        }
    }

    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    trie t;
    string s;
    cin >> s;
    for (ll pos = s.size() - 1; pos > -1; --pos) {
        t.insert(s.substr(pos));
    }
    cout << CNT -1<< endl;
    /*
    while(q--) {
        string s;
        cin >> s;
        if (isdigit(s[0])) {
            int k = stoi(s);
            string res = t.lexString(k);
            cout << res << '\n';
            t.erase(res);
        } 
        else
            t.insert(s);
    }
    */
    return 0;
}