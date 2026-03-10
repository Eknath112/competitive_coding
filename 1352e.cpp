#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    if(cin >> t) {
        while(t--) {
            int n; cin >> n;
            vector<int> a(n);
            vector<int> cnt(n + 1, 0);
            for(int i=0; i<n; i++) {
                cin >> a[i];
                cnt[a[i]]++;
            }
            int ans = 0;
            for(int i=0; i<n; i++) {
                int sum = a[i];
                for(int j=i+1; j<n; j++) {
                    sum += a[j];
                    if(sum <= n) {
                        ans += cnt[sum];
                        cnt[sum] = 0;
                    } else {
                        break;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
