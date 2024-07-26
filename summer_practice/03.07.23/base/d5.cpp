#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    map<string, pair<string, bool>> db;
    while (getline(cin, s)) {
        int end = s.find(' ');
        string com = s.substr(0, end);
        s.erase(0, end+1);
        if (com == "register") {
            end = s.find(' ');
            string login = s.substr(0, end);
            if (db.contains(login)) {
                cout << "login already in use"<< endl;
            }
            else {
                s.erase(0, end+1);
                end = s.find(' ');
                string passwd = s.substr(0, end);
                db[login].first = passwd;
                db[login].second = false;
                cout << "account created"<< endl;
            }
        }
        if (com == "login") {
            end = s.find(' ');
            string login = s.substr(0, end);
            if (!db.contains(login)) {
                cout << "wrong account info"<< endl;
            }
            else {
                s.erase(0, end+1);
                end = s.find(' ');
                string passwd = s.substr(0, end);
                if (db[login].first != passwd) {
                    cout << "wrong account info"<< endl;
                }
                else if (db[login].second == true) {
                    cout << "already logged in"<< endl;
                }
                else {
                    db[login].second = true;
                    cout << "logged in" << endl;
                }
            }
        }
        if (com == "logout") {
            end = s.find(' ');
            string login = s.substr(0, end);
            if (!db.contains(login)) {
                cout << "incorrect operation"<< endl;
            }
            else if (db[login].second != true) {
                cout << "incorrect operation"<< endl;
            }
            else {
                db[login].second = false;
                cout << "logged out" << endl;
            }
        }
    }
    return 0;
}