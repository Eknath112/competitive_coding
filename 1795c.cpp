#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; 
    if(cin >> t) {
        while(t--) {
            int n; cin >> n;
            vector<long long> a(n), b(n), pref(n + 1, 0);
            for(int i=0; i<n; i++) cin >> a[i];
            for(int i=0; i<n; i++) {
                cin >> b[i];
                pref[i + 1] = pref[i] + b[i];
            }
            vector<long long> count(n + 2, 0), rem(n + 2, 0);
            for(int i=0; i<n; i++) {
                int pos = upper_bound(pref.begin() + i + 1, pref.end(), pref[i] + a[i]) - pref.begin() - 1;
                count[i]++;
                count[pos]--;
                rem[pos] += a[i] - (pref[pos] - pref[i]);
            }
            long long cur = 0;
            for(int i=0; i<n; i++) {
                cur += count[i];
                cout << cur * b[i] + rem[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}
