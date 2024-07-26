    #include <iostream>
    #include <vector>
    #include <cmath>
     
    using namespace std;
     
    using ll= unsigned long long;
     
    int main() {
        cin.tie(0);
        ios_base::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t--) {
            cout << "? 0" << endl;
            int n;
            int deg=0, root=1;
            cin >> n;
            if (n == 0) {
                cout << "! 1 0\n";
                continue;
            }
            if (n == 1) {
                cout << "! 1 1\n";
                continue;
            }
            while (n%2 == 0){
                root = 2;
                n = n/2;
                ++deg;
            }
            for (int i = 3; i*i <= n; i = i+2){
                while (n%i == 0){
                    root = i;
                    deg++;
                    n = n/i;
                }
            }
            if (n > 2) {
                deg++;
                root = n;
            }
            cout << "! " << deg << ' ' << root << endl;
        }
        return 0;
    }