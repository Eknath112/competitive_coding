#include <bits/stdc++.h>
using namespace std;
long long count_inv(vector<int>& a) {
    long long ones = 0, inv = 0;
    for(int x : a) {
        if(x == 1) ones++;
        else inv += ones;
    }
    return inv;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; 
    if(cin >> t) {
        while(t--) {
            int n; cin >> n;
            vector<int> a(n);
            int first_zero = -1, last_one = -1;
            for(int i=0; i<n; i++) {
                cin >> a[i];
                if(a[i] == 0 && first_zero == -1) first_zero = i;
                if(a[i] == 1) last_one = i;
            }
            long long ans = count_inv(a);
            if(first_zero != -1) {
                a[first_zero] = 1;
                ans = max(ans, count_inv(a));
                a[first_zero] = 0;
            }
            if(last_one != -1) {
                a[last_one] = 0;
                ans = max(ans, count_inv(a));
                a[last_one] = 1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
