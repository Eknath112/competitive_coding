#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; 
    if(cin >> t) {
        while(t--) {
            int q; cin >> q;
            long long cntA = 1, cntB = 1;
            bool otherB = false;
            while(q--) {
                long long d, k; string x;
                cin >> d >> k >> x;
                for(char c : x) {
                    if(d == 1) {
                        if(c == 'a') cntA += k;
                    } else {
                        if(c == 'a') cntB += k;
                        else otherB = true;
                    }
                }
                if(otherB) {
                    cout << "YES\n";
                } else {
                    if(cntA < cntB) cout << "YES\n";
                    else cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
