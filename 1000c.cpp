#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    if(cin >> n) {
        map<long long, int> events;
        for(int i=0; i<n; i++) {
            long long l, r; cin >> l >> r;
            events[l]++;
            events[r + 1]--;
        }
        vector<long long> ans(n + 1, 0);
        long long prev = -1;
        int cur = 0;
        for(auto& p : events) {
            if(prev != -1) {
                ans[cur] += p.first - prev;
            }
            cur += p.second;
            prev = p.first;
        }
        for(int i=1; i<=n; i++) cout << ans[i] << (i == n ? "" : " ");
        cout << "\n";
    }
    return 0;
}
